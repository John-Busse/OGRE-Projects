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

		void Load() override;
		void Tick(float dt) override;

		void CreateLight();
		void CreateSkybox();
		void CreateEntities();

		/* a recursive function using a position vector3 stack to handle inherited movement
		@param numMoons the number of moons this planet has
		@param dt delta time */
		void SetPos(int, float);
	private:
		int stackIndex;
		std::stack<Ogre::Vector3> posStack;
};
