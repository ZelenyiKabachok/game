#ifndef PLANE_H
#define PLANE_H

#include "physical_object.h"
#include "aircraft_parts.h"

//Класс Plane создаёт самолёт.
//Является управляющим для классов PlaneBody, PlaneEngine, PlaneWing, PlaneTail.
class Plane {

	PlaneBody body;
	PlaneEngine engine;
	PlaneWing wing;
	PlaneTail tail;

	float TotalWeight; //Вес самолёта.
	float AverResistCoof; //Средний коэффициент сопротивления воздуха

	float PlaneSpeed;

public:
	
	Plane(PlaneBody& Abody, PlaneEngie& Aengine, PlaneWing& Awing,
									PlaneTail& Atail, float speed);
		
	void Move();

	void KeyInput(bool gas, bool brake); 

	void MouseInput();

};
	

#endif
