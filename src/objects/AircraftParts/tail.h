#ifndef TAIL_H
#define TAIL_H

#include "../physical_object.h"
#include "../shape.h"

namespace Aircraft {

enum planeTails { RUST_TAIL };

//Хвост для самолёта.
//Направляет самолёт.
class Tail : public Physic::PhysicObject {
	friend class Plane;

	const enum planeTails Name;
	const unsigned int num_shapes; //количество фигур самолёта для коллизии.

	float DirAngle = 0.0; //Угол для расчёта вектора направления.
//	vec3 direction; //Еденичный вектор направления.

	float PlaneAngle = 0.0; //Угол наклона самолёта.

//Изменяет вектор направления самолёта.
//Управление мышью.
	void FindDirect(float alpha);

	virtual void GetShapes(Physic::Shape** ppPlaneShapes, unsigned int& pos) {};

//Находит угол наклона cамолёта.
	void FindAngle(const glm::vec3& PlaneSpeed);

public:

	Tail(enum planeTails name, unsigned int nshapes
					, float m, float coof
					, const Graphic::Shader& sh
                    , const Graphic::Texture2D& tex
					, const glm::vec3& v3Pos = glm::vec3(0)
                    , const glm::vec3& v3Size = glm::vec3(1)
					, const glm::vec3& v3Speed = glm::vec3(0));

	virtual ~Tail() {}

};
}

#endif
