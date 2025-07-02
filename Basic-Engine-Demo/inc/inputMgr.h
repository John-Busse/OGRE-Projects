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
/*		bool keyPressed(const OIS::KeyEvent& evt) override;
		bool keyReleased(const OIS::KeyEvent& evt) override { return true; }
		bool mouseMoved(const OIS::MouseEvent& evt) override { return true; }
		bool mousePressed(const OIS::MouseEvent& evt, OIS::MouseButtonID id) override { return true; }
		bool mouseReleased(const OIS::MouseEvent& evt, OIS::MouseButtonID id) override { return true; }
*/
		void ProcessInput(float deltaTime);
		void UpdateCamera(float deltaTime);
		//void WindowResized(Ogre::RenderWindow* window);
	private:
		constexpr static float cameraStep = 25.0f;
		constexpr static float desiredVelocityStep = 10.0f;
		constexpr static float desiredAnglesStep = 30.0f;

		//input vars
		bool inputShift = false;
		int desiredSpeedStep = 0;
		int desiredHeadingStep = 0;
		int cameraPitchStep = 0;
		int cameraYawStep = 0;
		Ogre::Vector3 cameraMoveStep = Ogre::Vector3::ZERO;

		Ogre::Vector3 cameraMoveVec = Ogre::Vector3::ZERO;


};
