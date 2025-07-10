/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Solar System
 * Engine class declarations
*/
#pragma once

#include "main.h"
#include "mgr.h"
#include "camMgr.h"
#include "entityMgr.h"
#include "simMgr.h"
#include "gfxMgr.h"
#include "inputMgr.h"
#include "uiMgr.h"

// forward declarations
class CamMgr;
class EntityMgr;
class SimMgr;
class GfxMgr;
class InputMgr;
class UIMgr;

class Engine {
    public:
        Engine();
        ~Engine();

        void Run();
        void TickAll(float dt);
        void Cleanup();

        EntityMgr *entityMgr;
        SimMgr *simMgr;
        GfxMgr *gfxMgr;
        CamMgr *camMgr;
        InputMgr *inputMgr;
        UIMgr *uiMgr;

        bool IsRunning() const { return running; }
        void SetSpeed(bool up);
        float GetSpeed() const { return simSpeed * 0.1; }
        void Stop() { running = false; }    //Sets running to false
    
    private:
        bool running;
        int simSpeed;
        std::vector<Mgr*> managers;
};
