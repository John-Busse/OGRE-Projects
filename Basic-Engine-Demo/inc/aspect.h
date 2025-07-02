/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Basic Game Engine Demo
 * Aspect class definition
 */

#pragma once

#include "main.h"
#include "entity.h"

class Entity;	// Forward declaration of the Entity class

class Aspect {
	public:
		Aspect(Entity* ent) : entity(ent) {}
		virtual ~Aspect() {}

		virtual void Tick(float dt) {}

		Entity* entity = nullptr;
};

class Renderable : public Aspect {
	public:
		Renderable(Entity* ent) : Aspect(ent) {}
		~Renderable() {}

		void Tick(float dt);
};

class Physics2D : public Aspect {
	public:
		Physics2D(Entity* ent) : Aspect(ent) {}
		~Physics2D() {}

		void Tick(float dt);
};
