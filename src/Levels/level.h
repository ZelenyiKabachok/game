#ifndef LEVEL_H
#define LEVEL_H

#include "../loads.h"
#include "../objects.h"

class ILevel {
/*
	GraphObject *GrObjects;

	PhysicObject *PhObjects;

	Plane *plane;
*/
public:

	virtual void Load() = 0;

	virtual void UpDate(float delta_time) = 0;

	virtual ~ILevel() {}
};

#endif
