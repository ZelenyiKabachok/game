#ifndef PLANE_H
#define PLANE_H

#include "physical_object.h"
#include "aircraft_parts.h"

//Класс Plane создаёт самолёт.
//Управляющий для классов Body, Engine, Wing, Tail.
class Plane {

	Body body;
	Engine engine;
	Wings wings;
	Tail tail;

	float TotalWeight = 0; //Вес самолёта.
	float AverResistCoof = 0; //Средний коэффициент сопротивления воздуха

	float PlaneSpeed;
    
//Расставляет части самолёта по местам.
//Считает общий вес самолёта и коэффициент сопротивления воздуха.
	void Build();
/*
	void KeyInput(bool gas, bool brake); 

	void MouseInput(float angle);
*/
public:
	
	Plane(Body& Abody, Engine& Aengine, Wings& Awing, Tail& Atail, float speed);
		
	void Fly(bool gas, bool brake, float angle);
};
	

#endif
