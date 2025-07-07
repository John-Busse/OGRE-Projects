/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Basic Game Engine Demo
 * Entity manager child class declaration
 */

#include "simMgr.h"
#include "engine.h"

SimMgr::SimMgr(Engine *engine) : Mgr(engine) {
	this->engine = engine;
}

SimMgr::~SimMgr() {

}

void SimMgr::Init() {
	CreateScene();
}

void SimMgr::Load() {

}

void SimMgr::Tick(float dt) {

}

void SimMgr::Stop() {

}

void SimMgr::CreateScene() {
	CreateSkybox();
	CreateEntities();
}

void SimMgr::CreateSkybox() {
	//TODO: Custom Skybox material
	engine->gfxMgr->GetSceneMgr()->setSkybox(true, "Examples/Space");

	engine->gfxMgr->GetSceneMgr()->setAmbientLight(Ogre::ColourValue(0.1, 0.1, 0.1));
	engine->gfxMgr->GetSceneMgr()->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_MODULATIVE);
}

void SimMgr::CreateEntities() {
	std::ifstream fin("planetInfo.json");
	json data = json::parse(fin);
	int moons = 0;
	for (int i = 0; i < data.size(); i++) {
		PlanetInfo* pInfo = new PlanetInfo();
		pInfo->name = data[i]["name"];
		pInfo->numMoons = data[i]["numMoons"];
		pInfo->scale = data[i]["scale"];
		pInfo->orbitDist = data[i]["orbitDist"];
		pInfo->orbitTilt = data[i]["orbitTilt"];
		pInfo->rotateSpeed = data[i]["rotateSpeed"];
		pInfo->sceneName = data[i]["sceneName"];

		if (pInfo->numMoons > 0 && i > 0)
			moons = pInfo->numMoons;
		Ogre::Vector3 position = Ogre::Vector3(pInfo->orbitDist, 0, 0);
		engine->entityMgr->CreateEntity(this->engine, pInfo->sceneName, i, pInfo);
	}
}
