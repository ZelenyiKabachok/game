#ifndef PLANE_H
#define PLANE_H

#include "aircraft_parts.h"
#include "collision.h"

//Класс Plane создаёт самолёт.
//Управляющий для классов Body, Engine, Wing, Tail.

//enum PlaneParts = {	BODY, ENGINE, WINGS, TAIL };

class Plane {

	Body body;
	Engine engine;
	Wings wings;
	Tail tail;

	//Collision& collision;

	float TotalWeight = 0; 		//Вес самолёта.
	float AverResistCoof = 0; 	//Средний коэффициент сопротивления воздуха.

	vec3 PlaneSpeed;

//Расставляет части самолёта по местам.
//Считает общий вес самолёта и коэффициент сопротивления воздуха.
	void Build();

	void Init();

//Меняет расположение частей самолёта относительно
//его корпуса.
	void ChangePosParts();

public:
	
	Plane(const Body& Abody, const Engine& Aengine, const Wings& Awing,
		  const Tail& Atail, const vec3& pos, const vec3& speed);
		
	void Fly(float delta_time, bool gas, bool brake, float angle);

	void Render(const Camera& camera) const;

	void PrintPlaneState() const;

	const Body& GetBody() const;

	void ChangeBody(Body& Abody);
	void ChangeEngine(Engine& Aengine);
	void ChangeWings(Wings& Awing);
	void ChangeTail(Tail& Atail);
};

#endif
