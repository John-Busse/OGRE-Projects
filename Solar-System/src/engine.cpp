/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Solar System
 * Engine class definition
*/
#include "main.h"
#include "engine.h"
#include "camMgr.h"
//#include "entityMgr.h"
//#include "simMgr.h"
#include "gfxMgr.h"
//#include "inputMgr.h"
//#include "uiMgr.h"

Engine::Engine()
    : entityMgr(nullptr), 
    simMgr(nullptr), 
    gfxMgr(nullptr), 
    inputMgr(nullptr), 
    uiMgr(nullptr), 
    running(true) {
    }

Engine::~Engine() {
}

void Engine::Init() {
    // Initialize managers here
    entityMgr = new EntityMgr();
    simMgr = new SimMgr();
    gfxMgr = new GfxMgr();
    camMgr = new CamMgr();
    inputMgr = new InputMgr();
    uiMgr = new UIMgr();

    entityMgr->Init();
    simMgr->Init();
    gfxMgr->Init();
    camMgr->Init();
    inputMgr->Init();
    uiMgr->Init(); 

    // Load resources and set up the engine
    entityMgr->Load();
    simMgr->Load();
    gfxMgr->Load();
    camMgr->Load();
    inputMgr->Load();
    uiMgr->Load();
}

void Engine::TickAll(float deltaTime) {
    // Call Tick on all managers
    entityMgr->Tick(deltaTime);
    simMgr->Tick(deltaTime);
    gfxMgr->Tick(deltaTime);
    camMgr->Tick(deltaTime);
    inputMgr->Tick(deltaTime);
    uiMgr->Tick(deltaTime);
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
    if (entityMgr) {
        entityMgr->Stop();
        delete entityMgr;
    }
    if (simMgr) {
        simMgr->Stop();
        delete simMgr;
    }
    if (gfxMgr) {
        gfxMgr->Stop();
        delete gfxMgr;
    }
    if (camMgr) {
        camMgr->Stop();
        delete camMgr;
    }
    if (inputMgr) {
        inputMgr->Stop();
        delete inputMgr;
    }
    if (uiMgr) {
        uiMgr->Stop();
        delete uiMgr;
    }
}