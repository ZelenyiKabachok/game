#ifndef ENGINE_H
#define ENGINE_H

#include "physic_object.h"

//Двигатель для самолёта
class PlaneEngine : public PhysObject {

	const float maxThrustForce; 	//Максимальная сила тяги двигателя
	float curThrustForce; 			//Текущая силя тяги двигателя
	const float boostThrustForce; 	//Изменение силы тяги двигателя
	float fuel consumption;			//Расход топлива

public:

	PlaneEngine();

//Обновляет состояние объекта.
//Вызывает метод void AttractAndMove(float, const vec3&, const vec3&, float)
	void UpDate(const float delta_time, bool gas = 0, bool brake = 0);

};
