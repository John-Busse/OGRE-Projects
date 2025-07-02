/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Basic Game Engine Demo
 * Engine class definition
 */

#pragma once

#include "entityMgr.h"
#include "gameMgr.h"
#include "gfxMgr.h"
#include "inputMgr.h"
#include "mgr.h"

class EntityMgr; // Forward declaration of the EntityMgr class
class GameMgr; // Forward declaration of the GameMgr class
class GfxMgr; // Forward declaration of the GfxMgr class
class InputMgr; // Forward declaration of the InputMgr class

class Engine {
	public:
		Engine();
		~Engine();

		EntityMgr* entityMgr;
		GameMgr* gameMgr;
		GfxMgr* gfxMgr;
		InputMgr* inputMgr;

		void Init();
		void Run();
		void TickAll(float);
		void Cleanup();

		bool GetRunning() { return running; }
		void SetRunning(bool run) {	running = run; }

	private:
		bool running;
};
