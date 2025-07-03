/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Basic Game Engine Demo
 * Graphics Manager child class declaration
 */

#include "gfxMgr.h"

GfxMgr::GfxMgr(Engine* engine) : Mgr(engine),
OgreBites::ApplicationContext("Basic Game Engine Demo") ,
mRoot(nullptr),
mResourcesCfg(Ogre::BLANKSTRING),
mPluginsCfg(Ogre::BLANKSTRING),
mSceneMgr(nullptr),
mCameraNode(nullptr),
mShaderGen(nullptr){
	this->engine = engine;
}

GfxMgr::~GfxMgr() {
	Stop();
	delete mRoot;
}

void GfxMgr::Init() {

}

void GfxMgr::setup() {
	//call the base class setup
	mRoot = getRoot();
	mRoot->initialise(false);
	createWindow("Basic Game Engine Demo", 1280, 720);

    locateResources();
    initialiseRTShaderSystem();
    loadResources();

    mRoot->addFrameListener(this);

	mResourcesCfg = "resources.cfg";
	mPluginsCfg = "plugins.cfg";

	Ogre::ConfigFile cf;
	cf.load(mResourcesCfg);

	//get a pointer to the root and make the scene manager

	mSceneMgr = mRoot->createSceneManager();
	mSceneMgr->addRenderQueueListener(mOverlaySystem);

	Ogre::ConfigDialog* cfgDialog = nullptr;

	if (!(mRoot->restoreConfig() || mRoot->showConfigDialog(cfgDialog))) {
		throw std::runtime_error("Can't restore config or show dialogue");
	}

	//register the scene with RTSS
	mShaderGen = Ogre::RTShader::ShaderGenerator::getSingletonPtr();
	mShaderGen->addSceneManager(mSceneMgr);

	// initialize camera
	Ogre::Camera* mCamera = mSceneMgr->createCamera("MainCam");
	mCamera->setNearClipDistance(5);

	mCameraNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	mCameraNode->setPosition(0, 200, 800);
	mCameraNode->lookAt(Ogre::Vector3(0, 0, 0), Ogre::Node::TransformSpace::TS_WORLD);
	mCameraNode->attachObject(mCamera);

	//add viewport
	Ogre::Viewport* viewport = getRenderWindow()->addViewport(mCamera);
	viewport->setBackgroundColour(Ogre::ColourValue(0.0f, 0.0f, 0.0f));
	mCamera->setAspectRatio(
		Ogre::Real(viewport->getActualWidth()) / Ogre::Real(viewport->getActualHeight()));
}

void GfxMgr::LoadLevel() {
	//mRoot->startRendering();
}

void GfxMgr::Tick(float dt) {
	//Ogre::WindowEventUtilities::messagePump();
	if (getRenderWindow()->isClosed() || !mRoot->renderOneFrame()) {
		engine->SetRunning(false);
	}
}

void GfxMgr::Stop() {
	//closeApp();
	mRoot->shutdown();
	engine->SetRunning(false);
}

bool GfxMgr::frameRenderingQueued(const Ogre::FrameEvent& evt) {
	if (getRenderWindow()->isClosed()) {
		return false;
	}
	return true;
}
