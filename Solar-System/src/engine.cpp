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
    : running(true),
	  simSpeed(1) {
            // Create managers
    entityMgr = new EntityMgr(this);
    managers.push_back(entityMgr);
    gfxMgr = new GfxMgr(this);
    managers.push_back(gfxMgr);
    simMgr = new SimMgr(this);
    managers.push_back(simMgr);
    camMgr = new CamMgr(this);
    managers.push_back(camMgr);
    inputMgr = new InputMgr(this);
    managers.push_back(inputMgr);
    uiMgr = new UIMgr(this);
    managers.push_back(uiMgr);

	//load initial data
	for (Mgr* manager : managers) {
		manager->Load();
	}
}

Engine::~Engine() {
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
    float delta = (newTime - oldTime);
    while (running) {
        TickAll(delta);

        newTime = timer->getMicroseconds() / MICROSEC_PER_SEC;
        delta = (newTime - oldTime);
        oldTime = newTime;
    }
    delete timer;
    timer = nullptr;
}

void Engine::Cleanup() {
    // Cleanup managers
    while (!managers.empty()) {
        managers.pop_back();
    }
    /*
	for (Mgr* manager : managers) {
		if (manager) {
			delete manager;
		}
	}*/
	managers.clear();
}

void Engine::SetSpeed(bool up) {
	int speed = 1 * (up ? 1 : -1);

	simSpeed += speed;
	simSpeed = Clamp <int> (-1, 3, simSpeed);
}
