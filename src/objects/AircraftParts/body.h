#ifndef BODY_H
#define BODY_H

#include "../physical_object.h"

namespace AircraftParts {

//Корпус для самолёта.
//Содержит информация о количестве топлива.
class Body : public PhysicObject {
	friend class Plane;

//Максимальный объём топливного бака
	const float fualTankSize;

//Текущий объём топливного бака 
	float curFuelQuantity;

	void BurnFuel(float fuelConsumption);

public:

	Body(PhysicObject& body, float fualSize);

};

}
#endif
