#ifndef WINGS_H
#define WINGS_H

#include "../physical_object.h"

namespace AircraftParts {

//Крылья самолёта.
//Расчитывает силу подъёма.
class Wings : public PhysicObject {
	friend class Plane;

//Коэфициент силы подъёма, чем больше тем быстрее поднимает высоту.
	const float liftingCoof;
//Коэфициент сопротивления воздуха при торможении.
	const float coofResBrake;
//Коэфициент сопротивления воздуха в обычном состоянии.
	const float coofResNorm = coofResistance;

//Подъёмная сила.
	vec3 liftingForce = liftingCoof * ObSpeed;

//Меняет коэфициент силы сопротивления воздуха.
//При торможении coofResistance устанавливается в coofResBrake.
	void Fly(bool gas, bool brake);

public:

	Wings(PhysicObject& wings, float coofBrake, float lCoof);

};

}

#endif
