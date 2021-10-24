#ifndef ENGINE_H
#define ENGINE_H

#include "../physical_object.h"

namespace AircraftParts {

//Двигатель для самолёта.
//Расчитывает силу тяги.
class Engine : public PhysicObject {
	friend class Plane;

	const float maxThrustForce; 	//Максимальная сила тяги двигателя

//Вектор текущей силы тяги двигателя.
//Всегда сонаправлен вектору скорости самолёта.
	vec3 ThrustForce; 				

//Вектор изменения силы тигя двигателя.
//Сонаправлен вектору силы тяги двигателя.
	vec3 boostThrustForce;
	const float boostThrFor; 		//Изменение силы тяги двигателя
	const float averFuelConsumption;//Средний расход топлива при нормальной работе
	float fuelConsumption;			//Расход топлива

	//Обновляет состояние объекта.
	virtual void Work(const float delta_time, const vec3& direct, 
									bool gas = 0, bool brake = 0);

	virtual void SideEffect();

	//void ChangeAverFuelConsumption(float newConsumption)
	
	void CalcFuelConsumption(const float delta_time);
	
	bool MaxForce(const float delta_time);

public:

	Engine(PhysicObject engine, float maxForce, float startForce, 
				float boost, float consumption);

};

}

#endif
