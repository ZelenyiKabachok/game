#ifndef TAIL_H
#define TAIL_H

#include "../physical_object.h"

namespace AircraftParts {

//Хвост для самолёта.
//Направляет самолёт.
class Tail : public PhysicObject {
	friend class Plane;

	const float maxAngle; //Максимальный угол наклона.
	float angle; //Угол наклона.
	vec3 direction; //Еденичный вектор направления.


//Изменяет вектор направления самолёта.
//Управление мышью.
	void SetDirect();

public:

	Tail(PhysicObject& tail, float mAngle, float ang);

};

}

#endif
