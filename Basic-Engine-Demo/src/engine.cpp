/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Basic Game Engine Demo
 * Engine class declaration
 */

#include "engine.h"

class EntityMgr; // Forward declaration of the EntityMgr class

Engine::Engine() {
	entityMgr = nullptr;
	gameMgr = nullptr;
	gfxMgr = nullptr;
	inputMgr = nullptr;
	running = true;
}

Engine::~Engine(){
}

void Engine::Init() {
	entityMgr = new EntityMgr(this);
	gameMgr = new GameMgr(this);
	gfxMgr = new GfxMgr(this);
	inputMgr = new InputMgr(this);

	entityMgr->Init();
	gfxMgr->initApp();	//initApp is a method from OgreBites::ApplicationContext
	inputMgr->Init();
	gameMgr->Init();

	entityMgr->LoadLevel();
	gfxMgr->LoadLevel();
	inputMgr->LoadLevel();
	gameMgr->LoadLevel();
}

void Engine::TickAll(float delta) {
	gfxMgr->Tick(delta);
	inputMgr->Tick(delta);
	entityMgr->Tick(delta);
	gameMgr->Tick(delta);
}

void Engine::Run() {
	const float MICROSEC_PER_SEC = 1000000.0f;
	Ogre::Timer *timer = new Ogre::Timer();

	float oldTime = timer->getMicroseconds() / MICROSEC_PER_SEC;
	float newTime = timer->getMicroseconds() / MICROSEC_PER_SEC;
	float delta = newTime - oldTime;

	while (GetRunning()) {
		TickAll(delta);

		newTime = timer->getMicroseconds() / MICROSEC_PER_SEC;
		delta = newTime - oldTime;
		oldTime = newTime;
	}
}

void Engine::Cleanup() {
	inputMgr->Stop();
	gfxMgr->Stop();
	entityMgr->Stop();
	gameMgr->Stop();
}
