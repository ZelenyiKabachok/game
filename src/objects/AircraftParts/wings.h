#ifndef WINGS_H
#define WINGS_H

#include "../physical_object.h"
#include "../shape.h"

namespace Aircraft {

enum planeWings { RUST_WINGS };

//Крылья самолёта.
//Расчитывает силу подъёма.
class Wings : public Physic::PhysicObject {
	friend class Plane;

	const enum planeWings Name;
	const unsigned int num_shapes; //количество фигур самолёта для коллизии.

//Коэфициент силы подъёма, чем больше тем быстрее поднимает высоту.
	const float liftingCoof;
//Коэфициент сопротивления воздуха при торможении.
	const float coofResBrake;
//Коэфициент сопротивления воздуха в обычном состоянии.
	const float coofResNorm = coofResistance;

//Подъёмная сила.
	glm::vec3 v3LiftingForce;// = liftingCoof * v3Speed;

//Меняет коэфициент силы сопротивления воздуха.
//При торможении coofResistance устанавливается в coofResBrake.
	void CalcLiftForce(const glm::vec3& v3PlaneSpeed, float PlaneAngle
                                                , bool gas, bool brake);

	virtual void GetShapes(Physic::Shape** ppPlaneShapes, unsigned int& pos) {}

public:

	Wings(enum planeWings name, unsigned int nshapes
					, float coofBrake, float lCoof, float m, float coof
					, const Graphic::Shader& sh
                    , const Graphic::Texture2D& tex
					, const glm::vec3& v3Pos = glm::vec3(0)
                    , const glm::vec3& v3Size = glm::vec3(1)
					, const glm::vec3& v3Speed = glm::vec3(0)); 

	virtual ~Wings() {}

};
}

#endif
