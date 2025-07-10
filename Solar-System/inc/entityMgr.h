/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Basic Game Engine Demo
 * Entity manager child class definition
 */
#pragma once

#include "main.h"
#include "mgr.h"

//forward declarations
class Engine;
class Entity;

class EntityMgr : public Mgr {
	public:
		EntityMgr(Engine* Engine);
		~EntityMgr();

		void Load() override;
		void Tick(float dt) override;

		void CreateEntity(Ogre::Vector3, PlanetInfo*);

		Entity* GetSelected() const { return selectedEntity; }
		Entity* GetEntityByIndex(int) const;
		
		bool SetSelected(int index);
	private:
		int count = 0;
		Engine* engine;
		std::vector<Entity*> entities;
		Entity* selectedEntity = nullptr;
		int selectedIndex = -1;
};
