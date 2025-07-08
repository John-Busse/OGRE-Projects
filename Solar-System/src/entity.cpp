/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Basic Game Engine Demo
 * Entity class declaration
 */

#include "entity.h"
#include "engine.h"

Entity::Entity(Engine* engine, int id, PlanetInfo* pInfo, Ogre::Vector3 pos) :
	identity(id),
	info(pInfo),
	position(pos)
{	//Ogre::Vector3 pos
	// fill the data
	this->engine = engine;

	//instantiate and load the scene node
	sceneNode = engine->gfxMgr->getSceneMgr()->getRootSceneNode()->createChildSceneNode(position);
	Ogre::ResourceGroupManager::getSingleton().setWorldResourceGroupName(info->name);
	sceneNode->loadChildren(info->sceneName);
	sceneNode->setScale(Ogre::Vector3(info->scale));
	sceneNode->roll(Ogre::Degree(info->orbitTilt), Ogre::Node::TS_LOCAL);
	//sceneNode->setOrientation(Ogre::Quaternion())

	/*
	Ogre::SceneNode* attachmentNode = sceneMgr->getRootSceneNode->createChildSceneNode();

	Ogre::ResourceGroupManager::getSingleton().setWorldResourceGroupName(info->name);
	attachmentNode->loadChildren(pInfo->sceneName);
	 */
}

void Entity::Tick(float dt) {
	//TODO: physics here maybe?
	//render
	heading += info->rotateSpeed * dt;
	sceneNode->setPosition(position);
	//sceneNode->resetOrientation();
	sceneNode->yaw(Ogre::Degree(-heading));
}
