#ifndef PLANE_H
#define PLANE_H

//#include "physical_object.h"
#include "aircraft_parts.h"

//Класс Plane создаёт самолёт.
//Управляющий для классов Body, Engine, Wing, Tail.
class Plane {

	Body body;
	Engine engine;
	Wings wings;
	Tail tail;

	float TotalWeight = 0; 		//Вес самолёта.
	float AverResistCoof = 0; 	//Средний коэффициент сопротивления воздуха.

	vec3 PlaneSpeed;
    
//Расставляет части самолёта по местам.
//Считает общий вес самолёта и коэффициент сопротивления воздуха.
	void Build();

//Меняет расположение частей самолёта относительно
//его корпуса.
	void ChangePosParts();

public:
	
	Plane(Body& Abody, Engine& Aengine, Wings& Awing, Tail& Atail, vec3 speed);
		
	void Fly(float delta_time, bool gas, bool brake, float angle);

	void ChangeBody(Body& Abody);
	void ChangeEngine(Engine& Aengine);
	void ChangeWings(Wings& Awing);
	void ChangeTail(Tail& Atail);
};

#endif
