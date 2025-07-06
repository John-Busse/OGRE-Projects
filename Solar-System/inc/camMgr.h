/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Solar System
 * Camera Manager class declaration
*/
#pragma once

#include "main.h"
#include "mgr.h"

class CamMgr : public Mgr {
	public:
		CamMgr(Engine *engine);
		~CamMgr();

		void Init() override;
		void Load() override;
		void Tick(float) override;
		void Stop() override;

		void ResetAngle();

		void SetPos(Ogre::Vector3 pos);
		void SetRadius(float planetScale);

		void MoveX(bool right);
		void MoveY(bool up);
		void MoveZ(bool in, float scale);
	private:
		Ogre::SceneNode* cameraNode;

		Ogre::Vector3 camPos;
		Ogre::Vector3 focusPos;

		Ogre::Degree radius, theta, phi;
};
