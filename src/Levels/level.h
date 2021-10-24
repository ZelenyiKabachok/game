#ifndef LEVEL_H
#define LEVEL_H

#include "../objects.h"

class ILevel {
/*
	GraphObject *GrObjects;

	PhysicObject *PhObjects;

	Plane *plane;
*/
public:

	virtual void Load() = 0;

	virtual ~ILevel() {}
};

#endif
