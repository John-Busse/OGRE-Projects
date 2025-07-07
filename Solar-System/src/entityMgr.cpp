/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Basic Game Engine Demo
 * Entity manager child class declaration
 */
#include "entityMgr.h"
#include "engine.h"
#include "entity.h"

EntityMgr::EntityMgr(Engine* engine) : Mgr(engine) {
	this->engine = engine;
}

EntityMgr::~EntityMgr() {
	for (Entity* entity : entities) {
		delete entity;
	}
	entities.clear();
}

void EntityMgr::Init() {

}

void EntityMgr::Load() {

}

void EntityMgr::Stop() {

}

void EntityMgr::Tick(float dt) {
	for (int i = 0; i < entities.size(); i++) {
		entities[i]->Tick(dt);
	}
}

void EntityMgr::CreateEntity(std::string type, Ogre::Vector3 pos, PlanetInfo planetInfo) {
	Entity* entPtr;
	entPtr = new Entity(this->engine, type, pos, count);
	count++;
	entities.push_back(entPtr);
}

void EntityMgr::SelectNextEntity() {
	if (entities.size() <= 0) {
		throw std::runtime_error("Create a game entity before selecting one");

	if (selectedIndex >= 0)
		selectedEntity->SetSelected(false);
	selectedIndex = (selectedIndex + 1) % entities.size();
	selectedEntity = entities[selectedIndex];
	selectedEntity->SetSelected(true);
	}
}
