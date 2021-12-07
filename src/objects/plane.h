#ifndef PLANE_H
#define PLANE_H

#include "aircraft_parts.h"
#include "collision_pointers.h"
#include "../levels/object_loader.h"

//Класс Plane создаёт самолёт.
//Управляющий для классов Body, Engine, Wing, Tail.

namespace Aircraft {

class Plane {

//Не создаются. 
	Body *pBody;
	Engine *pEngine;
	Wings *pWings;
	Tail *pTail;

	Physic::Collision *pCollision;

	float TotalWeight = 0; 		//Вес самолёта.
	float AverResistCoof = 0; 	//Средний коэффициент сопротивления воздуха.

	glm::vec3 v3PlaneSpeed;

private:
//Расставляет части самолёта по местам.
//Считает общий вес самолёта и коэффициент сопротивления воздуха.
	void Build();

	void InitCollision(Physic::PCollisions& collObj);

//Меняет расположение частей самолёта относительно
//его корпуса.
	void ChangePosParts();

//Создаёт объекты
	void InitBody(planeBodies body_name, float *vertexes
                , unsigned int *indices, ObjectLoader& objects);
	void InitEngine(planeEngines engine_name, float *vertexes
                , unsigned int *indices, ObjectLoader& objects);
	void InitWings(planeWings wings_name, float *vertexes
                , unsigned int *indices, ObjectLoader& objects);
	void InitTail(planeTails tail_name, ObjectLoader& objects);

public:
	
   
    Plane(Aircraft::Body* body, Aircraft::Engine* engine
			    , Aircraft::Wings* wings, Aircraft::Tail *tail
			    , const glm::vec3& v3Pos, const glm::vec3& v3Speed
                , Physic::PCollisions& collObj);

	~Plane() {}

	void Fly(float delta_time, bool gas, bool brake, float angle);

	void Render(const Camera& camera) const;

	void PrintPlaneState() const;

	const Body& GetBody() const;

    void StartDrawCollision(Graphic::Shader& coll, Graphic::Shader& aabb
                        , Graphic::Texture2D& collTex);

};
}
#endif
