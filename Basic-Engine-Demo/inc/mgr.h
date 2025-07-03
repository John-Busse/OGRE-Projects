/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Basic Game Engine Demo
 * Manager class declaration
 */

#pragma once


class Engine;  // Forward declaration of the Engine class

class Mgr {
	public:
		Mgr();
		Mgr(Engine* engine) { this->engine = engine; };
		virtual ~Mgr() {};

		Engine* engine;

		virtual void Init();
		virtual void LoadLevel();
		virtual void Tick(float);
		virtual void Stop();
};

#include "engine.h"
