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

		void Init() override;
		void Load() override;
		void Tick(float) override;
		void Stop() override;

		void CreateEntity(Ogre::Vector3, PlanetInfo*);

		Entity* GetSelected() const { return selectedEntity; }
		Entity* GetEntityByIndex(int);
		bool SetSelected(int index) {
			bool newIndex = (index != selectedIndex);
			if (index > entities.size()) {
				throw std::runtime_error("EntityMgr::SetSelected() Error: index out of range\n");
			}

			selectedIndex = index;
			selectedEntity = entities[index];
			return newIndex;
		}
	private:
		int count = 0;
		Engine* engine;
		std::vector<Entity*> entities;
		Entity* selectedEntity = nullptr;
		int selectedIndex = -1;
};
