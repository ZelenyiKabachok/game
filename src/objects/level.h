#ifndef LEVEL_H
#define LEVEL_H

class Level {

	GraphObject *GrObjects;

	PhysicObject *PhObjects;

	Plane plane;

public:

	Level() {}

	virtual LoadLevel() = 0;

	virtual ~Level();

};

#endif
