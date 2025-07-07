/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Basic Game Engine Demo
 * Entity class declaration
 */

#include "entity.h"
#include "engine.cpp"

Entity::Entity(Engine* engine, int id, PlanetInfo* pInfo) {	//Ogre::Vector3 pos
	// fill the data
	this->engine = engine;

	identity = id;
	position = Ogre::Vector3(0, 0, 0);
	info = pInfo;

	//instantiate and load the scene node
	sceneNode = engine->gfxMgr->getSceneMgr()->getRootSceneNode()->createChildSceneNode();
	Ogre::ResourceGroupManager::getSingleton().setWorldResourceGroupName(info->name);
	sceneNode->loadChildren(info->sceneName);
	/*
	Ogre::SceneNode* attachmentNode = sceneMgr->getRootSceneNode->createChildSceneNode();

	Ogre::ResourceGroupManager::getSingleton().setWorldResourceGroupName(info->name);
	attachmentNode->loadChildren(pInfo->sceneName);
	 */
}

void Entity::Tick(float dt) {
	//TODO: physics here maybe?
	//render
	sceneNode->setPosition(position);
	sceneNode->resetOrientation();
	sceneNode->yaw(Ogre::Degree(-heading));
}
