/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Basic Game Engine Demo
 * Graphics Manager child class definition
 */

#pragma once

#include "engine.h"
#include "mgr.h"
#include "main.h"

//class Mgr; // Forward declaration of the Mgr class

class GfxMgr: public Mgr, public OgreBites::ApplicationContext {
	public:
		GfxMgr(Engine*);
		~GfxMgr();

		void Init();
		void setup() override;
		void LoadLevel();
		void Tick(float);
		void Stop();

		bool frameRenderingQueued(const Ogre::FrameEvent&);

		Ogre::SceneManager* GetSceneMgr() const { return mSceneMgr; }

		Ogre::SceneNode* GetCameraNode() const { return mCameraNode; }
	private:
		Ogre::Root *mRoot;
		Ogre::String mResourcesCfg;
		Ogre::String mPluginsCfg;
		Ogre::SceneManager* mSceneMgr;
		//Ogre::Camera* mCamera;
		Ogre::SceneNode* mCameraNode;
		Ogre::RTShader::ShaderGenerator* mShaderGen;
};
