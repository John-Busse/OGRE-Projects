/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Basic Game Engine Demo
 * Entity class declaration
 */

#include "entity.h"
#include "engine.cpp"

Entity::Entity(Engine* engine, std::string meshname, Ogre::Vector3 pos, int id) {
	this->engine = engine;

	identity = id;
	meshfilename = meshname;
	position = pos;
}

void Entity::Tick(float dt) {
	//TODO: physics here maybe?
	//render
	sceneNode->setPosition(position);
	sceneNode->resetOrientation();
	sceneNode->yaw(Ogre::Degree(-heading));
}
