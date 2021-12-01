#ifndef TAIL_H
#define TAIL_H

#include "../physical_object.h"
#include "../../utility/resources.h"

namespace Aircraft {

enum planeTails { RUST_TAIL };

//Хвост для самолёта.
//Направляет самолёт.
class Tail : public Physic::PhysicObject {
	friend class Plane;

	const enum planeTails Name;
    Physic::Collision collision;

	float DirAngle = 0.0; //Угол для расчёта вектора направления.
//	vec3 direction; //Еденичный вектор направления.

	float PlaneAngle = 0.0; //Угол наклона самолёта.

//Изменяет вектор направления самолёта.
//Управление мышью.
	void FindDirect(float alpha);

//Находит угол наклона cамолёта.
	void FindAngle(const glm::vec3& PlaneSpeed);

public:

	Tail(enum planeTails name, const char* fCollis
					, float m, float coof
					, Graphic::Shader& sh
                    , Graphic::Texture2D& tex
					, const glm::vec3& v3Pos = glm::vec3(0)
                    , const glm::vec3& v3Size = glm::vec3(1)
					, const glm::vec3& v3Speed = glm::vec3(0));

	virtual ~Tail() {}

};
}

#endif
