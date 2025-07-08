/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Solar System
 * Graphics Manager class definition
*/

#include "gfxMgr.h"
#include "engine.h"

GfxMgr::GfxMgr(Engine *engine)
	: Mgr(engine), 
	OgreBites::ApplicationContext("OGRE Solar System") {
	this->engine = engine;
	root = nullptr;
	sceneMgr = nullptr;
}

GfxMgr::~GfxMgr() {
	if (root) {
		delete root;
		root = nullptr;
	}
}

void GfxMgr::Init() {
	initApp();
}

void GfxMgr::setup() {
	// Initialize the root object
	root = getRoot();
	root->initialise(false);
	createWindow("Solar System", 1280, 720);

	locateResources();
	initialiseRTShaderSystem();
	loadResources();

	root->addFrameListener(this);

	Ogre::ConfigFile cf;
	cf.load("resources.cfg");

	sceneMgr = root->createSceneManager();
	sceneMgr->addRenderQueueListener(mOverlaySystem);

	Ogre::ConfigDialog* configDialog = nullptr;

	if (!(root->restoreConfig() || root->showConfigDialog(configDialog))) {
		throw std::runtime_error("Failed to restore or show config dialog");
	}

	//register the scene with RTSS
	Ogre::RTShader::ShaderGenerator* shaderGen = Ogre::RTShader::ShaderGenerator::getSingletonPtr();
	shaderGen->addSceneManager(sceneMgr);

}

void GfxMgr::Load() {
}

void GfxMgr::Tick(float deltaTime) {
	// Update the scene manager
	if (getRenderWindow()->isClosed() || !root->renderOneFrame()) {
		engine->Stop();
	}
}

void GfxMgr::Stop() {

}

bool GfxMgr::frameRenderingQueued(const Ogre::FrameEvent& evt) {
	// Handle frame rendering events
	if (getRenderWindow()->isClosed()) {
		return false;
	}

	return true;
}
