#ifndef PLANE_H
#define PLANE_H

#include "physical_object.h"
#include "aircraft_parts.h"

//Класс Plane создаёт самолёт.
//Управляющим для классов Body, Engine, Wing, Tail.
class Plane {

	Body body;
	Engine engine;
	Wings wings;
	Tail tail;

	float TotalWeight; //Вес самолёта.
	float AverResistCoof; //Средний коэффициент сопротивления воздуха

	float PlaneSpeed;
    
//Расставляет части самолёта по местам.
	void Build();

public:
	
	Plane(Body& Abody, Engine& Aengine, Wings& Awing, Tail& Atail, float speed);
		
	void Fly();

	void KeyInput(bool gas, bool brake); 

	void MouseInput();

};
	

#endif
