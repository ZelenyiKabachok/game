#ifndef TAIL_H
#define TAIL_H

#include "../physical_object.h"

//Хвост для самолёта.
//Направляет самолёт.
class Tail : public PhysicObject {
	friend class Plane;

	float angle; //Угол наклона.
	vec3 direction; //Еденичный вектор направления.

//Изменяет вектор направления самолёта.
//Управление мышью.
	void SetDirect(float alpha);

public:

	Tail(PhysicObject& tail, float alpha);

};

#endif
