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

void EntityMgr::CreateEntity(Ogre::Vector3 pos, PlanetInfo *planetInfo) {
	Entity* entPtr;
	entPtr = new Entity(this->engine, count, planetInfo, pos);
	count++;
	entities.push_back(entPtr);
}

Entity* EntityMgr::GetEntityByIndex(int index) {
	return entities[index];
}
