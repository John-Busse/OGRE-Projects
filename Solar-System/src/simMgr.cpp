/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Basic Game Engine Demo
 * Entity manager child class declaration
 */

#include "simMgr.h"
#include "engine.h"
#include "entity.h"

SimMgr::SimMgr(Engine *engine) : Mgr(engine) {
	this->engine = engine;
	stackIndex = 0;
}

SimMgr::~SimMgr() {

}

void SimMgr::Init() {
	CreateScene();
}

void SimMgr::Load() {

}

void SimMgr::Tick(float dt) {
	dt *= engine->GetSpeed();
	stackIndex = 0;
	posStack.push(Ogre::Vector3::ZERO);
	SetPos(1, dt);

	while (!posStack.empty()) {
		posStack.pop();
	}
}

void SimMgr::Stop() {

}

void SimMgr::CreateScene() {
	CreateLight();
	CreateSkybox();
	CreateEntities();
}

void SimMgr::CreateLight() {
	Ogre::Light* pointLight = engine->gfxMgr->getSceneMgr()->createLight("PointLight");
	pointLight->setType(Ogre::Light::LT_POINT);
	pointLight->setDiffuseColour(1.0, 1.0, 1.0);
	pointLight->setSpecularColour(1.0, 1.0, 1.0);

	Ogre::SceneNode* lightNode = engine->gfxMgr->getSceneMgr()->getRootSceneNode()->createChildSceneNode();
	lightNode->attachObject(pointLight);
	lightNode->setPosition(Ogre::Vector3(0, 0, 0));
}

void SimMgr::CreateSkybox() {
	//TODO: Custom Skybox material
	//engine->gfxMgr->getSceneMgr()->setSkyBox(true, "Examples/SpaceSkyBox", 60000);

	engine->gfxMgr->getSceneMgr()->setAmbientLight(Ogre::ColourValue(0.1, 0.1, 0.1));
	engine->gfxMgr->getSceneMgr()->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);
}

void SimMgr::CreateEntities() {
	std::ifstream fin("assets/planetInfo.json");
	json data = json::parse(fin);
	int moons = 0;
	std::vector<std::pair<float, int>> satellites;
	for (int i = 0; i < data.size(); i++) {
		float x = 0.0f;
		PlanetInfo* pInfo = new PlanetInfo();
		pInfo->name = data[i]["name"];
		pInfo->numMoons = data[i]["numMoons"];
		pInfo->scale = data[i]["scale"];
		pInfo->orbitDist = data[i]["orbitDist"];
		pInfo->orbitSpeed = data[i]["orbitSpeed"];
		pInfo->orbitTilt = data[i]["orbitTilt"];
		pInfo->rotateSpeed = data[i]["rotateSpeed"];
		pInfo->sceneName = data[i]["sceneName"];


		for (int i = 0; i < satellites.size(); i++) {
			if (satellites[i].second > 0) {
				x += satellites[i].first;
				satellites[i].second--;
			}
		}
		Ogre::Vector3 position = Ogre::Vector3(pInfo->orbitDist + x, 0, 0);
		//void EntityMgr::CreateEntity(std::string type, Ogre::Vector3 pos, PlanetInfo planetInfo) {
		engine->entityMgr->CreateEntity(position, pInfo);

		if (pInfo->numMoons > 0) {
			satellites.push_back(std::make_pair(pInfo->orbitDist, pInfo->numMoons));
		}
	}
	engine->entityMgr->SetSelected(0);
}

void SimMgr::SetPos(int numMoons, float dt) {
	for (int i = 0; i < numMoons; i++) {
		Entity* thisPlanet = engine->entityMgr->GetEntityByIndex(stackIndex);
		posStack.push(posStack.top());	//push copy of previous matrix
		thisPlanet->IncrementAngle(dt * engine->GetSpeed());
		// translate for orbit
		posStack.top() += Ogre::Vector3(	sin(thisPlanet->GetAngle()) * thisPlanet->GetPlanet()->orbitDist,
											0.0f,
											cos(thisPlanet->GetAngle()) * thisPlanet->GetPlanet()->orbitDist);

		thisPlanet->SetPosition(posStack.top());
		stackIndex++;

		if (thisPlanet->GetPlanet()->numMoons > 0) {
			SetPos(thisPlanet->GetPlanet()->numMoons, dt);
		}
		posStack.pop();

	}
}
