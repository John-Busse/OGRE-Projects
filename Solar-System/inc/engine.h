/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Solar System
 * Engine class declarations
*/
#pragma once

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

        void Init();
        void Run();
        void TickAll(float);
        void Cleanup();

        EntityMgr *entityMgr;
        SimMgr *simMgr;
        GfxMgr *gfxMgr;
        CamMgr *camMgr;
        InputMgr *inputMgr;
        UIMgr *uiMgr;

        bool IsRunning() const { return running; }
        void Stop() { running = false; }
    
    private:
        bool running;
};