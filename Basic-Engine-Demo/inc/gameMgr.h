/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Basic Game Engine Demo
 * Game Manager child class definition
 */

#pragma once

#include "main.h"
#include "engine.h"
#include "gfxMgr.h"
#include "entityMgr.h"
#include "mgr.h"

class GameMgr : public Mgr {
	public:
		GameMgr(Engine*);
		~GameMgr();

		Engine *engine;

		void Init();
		void LoadLevel();
		void Tick(float);
		void Stop();

		void CreateScene();
		void CreateGround();
		void CreateSkybox();
		void CreateEntities();
};
