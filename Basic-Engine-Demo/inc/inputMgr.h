/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Basic Game Engine Demo
 * Input Manager child class definition
 */

#pragma once

#include "main.h"
#include "engine.h"
#include "entityMgr.h"
#include "gfxMgr.h"
#include "mgr.h"

class InputMgr: public Mgr, public OgreBites::InputListener{
	public:
		InputMgr(Engine* engine);
		~InputMgr();

		Engine *engine;

		void Init();
		void LoadLevel();
		void Tick(float deltaTime);
		void Stop();

		bool keyPressed(const OgreBites::KeyboardEvent& evt) override;
		bool keyReleased(const OgreBites::KeyboardEvent& evt) override;

		bool isKeyDown(int key);

		void ProcessInput(float deltaTime);
		void UpdateCamera(float deltaTime);
		//void WindowResized(Ogre::RenderWindow* window);
	private:
		constexpr static float cameraStep = 1000.0f;
		constexpr static float desiredVelocityStep = 10.0f;
		constexpr static float desiredAnglesStep = 30.0f;

		Ogre::Vector3 cameraMoveVec = Ogre::Vector3::ZERO;

		std::map<int, bool> keyStates; // Track key states for continuous input handling
};
