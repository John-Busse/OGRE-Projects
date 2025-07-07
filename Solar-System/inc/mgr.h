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

        virtual void Init();
        virtual void Load();
        virtual void Tick(float);
        virtual void Stop();
    
    protected:
        Engine *engine;
};
