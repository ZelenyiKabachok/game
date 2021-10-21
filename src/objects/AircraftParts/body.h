#ifndef BODY_H
#define BODY_H

#include "../physical_object.h"

class PlaneBody : public PhysicObject {

//Коэфициент силы подъёма, чем больше тем быстрее поднимает высоту
	const float liftingCoof;

//Максимальный объём топливного бака (в литрах)
	const float fualTankSize;

//Текущий объём топливного бака 
	float curFuelQuantity;

public:

	PlaneBody();

};

#endif
