/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Solar System
 * Engine class definition
*/
#include "engine.h"
#include "camMgr.h"
#include "entityMgr.h"
#include "simMgr.h"
#include "gfxMgr.h"
#include "inputMgr.h"
#include "uiMgr.h"

Engine::Engine()
    : uiMgr(nullptr),
	  entityMgr(nullptr),
	  simMgr(nullptr),
	  gfxMgr(nullptr),
	  inputMgr(nullptr),
	  camMgr(nullptr),
	  running(true) {
    }

Engine::~Engine() {
}

void Engine::Init() {
    // Initialize managers here
    entityMgr = new EntityMgr(this);
    managers.push_back(entityMgr);
    simMgr = new SimMgr(this);
    managers.push_back(simMgr);
    gfxMgr = new GfxMgr(this);
    managers.push_back(gfxMgr);
    camMgr = new CamMgr(this);
    managers.push_back(camMgr);
    inputMgr = new InputMgr(this);
    managers.push_back(inputMgr);
    uiMgr = new UIMgr(this);
    managers.push_back(uiMgr);

    //initialize all managers
	for (Mgr* manager : managers) {
		manager->Init();
	}
	//load initial data
	for (Mgr* manager : managers) {
		manager->Load();
	}
}

void Engine::TickAll(float deltaTime) {
    // Call Tick on all managers
	for (Mgr* manager : managers) {
		manager->Tick(deltaTime);
	}
}

void Engine::Run() {
    const float MICROSEC_PER_SEC = 1000000.0f;
    Ogre::Timer *timer = new Ogre::Timer();

    float oldTime = timer->getMicroseconds() / MICROSEC_PER_SEC;
    float newTime = oldTime;
    float delta = newTime - oldTime;
    while (running) {
        TickAll(delta);

        newTime = timer->getMicroseconds() / MICROSEC_PER_SEC;
        delta = newTime - oldTime;
        oldTime = newTime;
    }
}

void Engine::Cleanup() {
    // Cleanup managers
	for (Mgr* manager : managers) {
		if (manager) {
			manager->Stop();
			delete manager;
		}
	}
	delete managers;
}
