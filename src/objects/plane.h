#ifndef PLANE_H
#define PLANE_H

#include "aircraft_parts.h"
#include "collision_pointers.h"

//Класс Plane создаёт самолёт.
//Управляющий для классов Body, Engine, Wing, Tail.

//enum PlaneParts = {	BODY, ENGINE, WINGS, TAIL };

class Plane {

	Body *body;
	Engine *engine;
	Wings *wings;
	Tail *tail;

//Дескриптор объекта Collision
	unsigned int collDescriptor;
	const Shader& shader;
	Collision *collision;

	float TotalWeight = 0; 		//Вес самолёта.
	float AverResistCoof = 0; 	//Средний коэффициент сопротивления воздуха.

	vec3 PlaneSpeed;

private:
//Расставляет части самолёта по местам.
//Считает общий вес самолёта и коэффициент сопротивления воздуха.
	void Build();

	void InitCollision(PCollisions& collObj);

//Меняет расположение частей самолёта относительно
//его корпуса.
	void ChangePosParts();

//Создаёт объекты
	void InitBody(planeBodies body_name, float *vertexes, unsigned int *indices);
	void InitEngine(planeEngines engine_name, float *vertexes, unsigned int *indices);
	void InitWings(planeWings wings_name, float *vertexes, unsigned int *indices);
	void InitTail(planeTails tail_name, float *vectexes, unsigned int *indices);

public:
	
	Plane(planeBodies body_name, planeEngines engine_name,
			 planeWings wings_name, planeTails tail_name,
			 const vec3& pos, const vec3& speed,
			 PCollisions& collObj, const Shader& planeShader);

	~Plane();
		
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
