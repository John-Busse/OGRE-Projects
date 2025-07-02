/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Basic Game Engine Demo
 * Entity class definition
 */

#pragma once

#include "main.h"
#include "aspect.h"
#include "engine.h"
#include "gfxMgr.h"

class Aspect; // Forward declaration of the Aspect class

class Entity {
	public:
		Entity(Engine*, std::string, Ogre::Vector3, int);
		virtual ~Entity() {}

		Engine* engine;

		void Tick(float dt);

		//getters
		//acceleration
		float GetTurnRate() const { return turnRate; }
		//minSpeed
		//maxSpeed
		Ogre::Vector3 GetPosition() const { return position; }
		//velocity
		bool GetSelected() const { return isSelected; }
		float GetDesiredHeading() const { return desiredHeading; }
		float GetDesiredSpeed() const { return desiredSpeed; }
		float GetHeading() const { return heading; }
		float GetSpeed() const { return speed; }
		//meshfilename
		Ogre::SceneNode* GetSceneNode() const { return sceneNode; }
		//ogreEntity

		//setters
		void SetAcceleration(float newAcceleration) {
			acceleration = newAcceleration;
		}
		void SetTurnRate(float newTurnRate) {
			turnRate = newTurnRate;
		}
		//min speed
		void SetMaxSpeed(float newMaxSpeed) {
			maxSpeed = newMaxSpeed;
		}
		void SetPosition(const Ogre::Vector3& pos) { position += pos; }
		//velocity
		void SetSelected(bool selected) { isSelected = selected; }
		void SetDesiredHeading(float newHeading) { desiredHeading = FixAngle(newHeading); }
		void IncrementDesiredHeading(float direction) {
			desiredHeading += direction;
			desiredHeading = FixAngle(desiredHeading);
		}
		void SetDesiredSpeed(float newSpeed) {
			desiredSpeed = std::clamp(minSpeed, maxSpeed, newSpeed);
		}
		void IncrementDesiredSpeed(float newSpeed) {
			desiredSpeed += newSpeed;
			desiredSpeed = Clamp(minSpeed, maxSpeed, desiredSpeed);
		}

		void IncrementHeading(float direction) {
			heading += turnRate * direction;
			heading = FixAngle(heading);
		}
		void IncrementSpeed(float newSpeed) {
			speed += acceleration * newSpeed;
			speed = Clamp(minSpeed, maxSpeed, speed);
		}
	protected:
		// Static data
		int identity;
		std::string name;
		float acceleration = 0, turnRate = 0;
		float minSpeed = 0, maxSpeed = 0;

		// Dynamic data
		Ogre::Vector3 position = Ogre::Vector3::ZERO;
		Ogre::Vector3 velocity = Ogre::Vector3::ZERO;
		bool isSelected = false;
		float desiredHeading = 0, desiredSpeed = 0;
		float heading = 0, speed = 0;

		std::string meshfilename;
		Ogre::SceneNode* sceneNode = nullptr;
		Ogre::Entity* ogreEntity = nullptr;
		// Aspects
		std::vector<Aspect*> aspects;

};

class Carrier: public Entity {
public:
	Carrier(Engine*, std::string, Ogre::Vector3, int);
	~Carrier() {}
};

class Destroyer: public Entity {
public:
	Destroyer(Engine*, std::string, Ogre::Vector3, int);
	~Destroyer() {}
};

class Cigarette: public Entity {
public:
	Cigarette(Engine*, std::string, Ogre::Vector3, int);
	~Cigarette() {}
};

class CG47: public Entity {
public:
	CG47(Engine*, std::string, Ogre::Vector3, int);
	~CG47() {}
};

class Tug: public Entity {
public:
	Tug(Engine*, std::string, Ogre::Vector3, int);
	~Tug() {}
};

class PolyPlane: public Entity {
public:
	PolyPlane(Engine*, std::string, Ogre::Vector3, int);
	~PolyPlane() {}
};
