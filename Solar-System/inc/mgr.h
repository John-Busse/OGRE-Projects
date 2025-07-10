/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Solar System
 * Manager class declaration
*/
#pragma once

class Engine;

class Mgr {
    public:
        Mgr(Engine *engine) : engine(engine) {}
        virtual ~Mgr() {}

        //Load initial dependent data
        virtual void Load() {}
        virtual void Tick(float dt) {}
    
    protected:
        Engine *engine;
};
