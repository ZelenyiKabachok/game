#ifndef BODY_H
#define BODY_H

#include "../physical_object.h"

enum planeParts { ENGINE, WINGS, TAIL };

//Корпус для самолёта.
//Содержит информация о количестве топлива.
class Body : public PhysicObject {
	friend class Plane;

//Максимальный объём топливного бака
	const float fualTankSize;

//Текущий объём топливного бака 
	float curFuelQuantity;
	
//Расположение всех частей самолёта относительно копруса.
	vec3 StartPartsPos[3];

	vec3 GetPartPos(enum planeParts part);

	void BurnFuel(float fuelConsumption);

public:

	Body(PhysicObject& body, float fualSize, vec3 *parts);

};

#endif
