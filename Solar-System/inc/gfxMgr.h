/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Solar System
 * Graphics Manager class declaration
*/
#pragma once

#include "main.h"
#include "mgr.h"

class GfxMgr : public Mgr, public OgreBites::ApplicationContext {
	public:
		GfxMgr(Engine *engine);
		~GfxMgr();

		void Init() override;
		void setup() override;
		void Load() override;
		void Tick(float) override;
		void Stop() override;

		bool frameRenderingQueued(const Ogre::FrameEvent&);

		//getters
		Ogre::SceneManager* getSceneMgr() { return sceneMgr; }

	private:
		Ogre::Root *root;
		Ogre::SceneManager* sceneMgr;
};
