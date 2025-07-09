/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Basic Game Engine Demo
 * Entity manager child class definition
 */
#pragma once

#include "main.h"
#include "mgr.h"

//forward declaration
class Engine;

class SimMgr : public Mgr {
	public:
		SimMgr(Engine* engine);
		~SimMgr();

		void Init() override;
		void Load() override;
		void Tick(float) override;
		void Stop() override;

		void CreateScene();

		void CreateLight();
		void CreateSkybox();
		void CreateEntities();

		void SetPos(int, float);
	private:
		int stackIndex;
		std::stack<Ogre::Vector3> posStack;
};
