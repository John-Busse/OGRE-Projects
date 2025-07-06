/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Solar System
 * Input Manager class declaration
*/
#pragma once

#include "main.h"
#include "mgr.h"

class InputMgr : public Mgr, public OgreBites::InputListener {
	public:
		InputMgr(Engine *engine);
		~InputMgr();

		void Init() override;
		void Load() override;
		void Tick(float) override;
		void Stop() override;

		// Input handling methods
		bool keyPressed(const OgreBites::KeyboardEvent& evt) override;
		bool keyReleased(const OgreBites::KeyboardEvent& evt) override;

		bool isKeyDown(int key);
		
		void ProcessInput(float);
		void UpdateCamera(float);

	private:
		Engine *engine;
		
		constexpr static float cameraStep = 1000.0f; // Camera movement speed
		constexpr static float desiredVelocityStep = 10.0f;
		constexpr static float desiredAngleStep = 30.0f;

		std::map<int, bool> keyStates; // Track key states for continuous input handling
};