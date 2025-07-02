/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Basic Game Engine Demo
 * Game Manager child class declaration
 */

#include "gameMgr.h"

GameMgr::GameMgr(Engine* engine) : Mgr(engine) {
	this->engine = engine;
}

GameMgr::~GameMgr() {
}

void GameMgr::Init() {
	CreateScene();
}

void GameMgr::LoadLevel() {
}

void GameMgr::Tick(float delta) {
}

void GameMgr::Stop() {
}

void GameMgr::CreateScene() {
	CreateGround();
	CreateSkybox();
	CreateEntities();
}

void GameMgr::CreateGround() {
	Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);

	Ogre::MeshManager::getSingleton().createPlane(
		"ocean",
		Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
		plane,
		10000, 10000, 20, 20,
		true,
		1, 5, 5,
		Ogre::Vector3::UNIT_Z);

	Ogre::Entity* groundEntity = engine->gfxMgr->GetSceneMgr()->createEntity("ocean");

	engine->gfxMgr->GetSceneMgr()->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);

	groundEntity->setMaterialName("Ocean2_HLSL_GLSL");
	groundEntity->setCastShadows(false);
}

void GameMgr::CreateSkybox() {
	engine->gfxMgr->GetSceneMgr()->setSkyBox(true, "Examples/MorningSkyBox");

	engine->gfxMgr->GetSceneMgr()->setAmbientLight(Ogre::ColourValue(0.75, 0.75, 0.75));
	engine->gfxMgr->GetSceneMgr()->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_MODULATIVE);
}

void GameMgr::CreateEntities() {
	float spacing = 250.0f;
	Ogre::Vector3 position = Ogre::Vector3(-spacing * 2, 0, 0);
	engine->entityMgr->CreateEntityOfTypeAtPosition(Ent_Tug, position);
	position.x += spacing;
	engine->entityMgr->CreateEntityOfTypeAtPosition(Ent_Carrier, position);
	position.x += spacing;
	engine->entityMgr->CreateEntityOfTypeAtPosition(Ent_Cig, position);
	position.x += spacing;
	engine->entityMgr->CreateEntityOfTypeAtPosition(Ent_CG47, position);
	position.x += spacing;
	engine->entityMgr->CreateEntityOfTypeAtPosition(Ent_Destroyer, position);

	position.y = 100;
	position.x = -spacing * 2;

	for (int i = 0; i < 5; i++) {
		engine->entityMgr->CreateEntityOfTypeAtPosition(Ent_PolyPlane, position);
		position.x += spacing;
	}

	engine->entityMgr->SelectNextEntity();

}

