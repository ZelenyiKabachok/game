#ifndef WINGS_H
#define WINGS_H

#include "../physical_object.h"

namespace Aircraft {

enum planeWings { RUST_WINGS };

//Крылья самолёта.
//Расчитывает силу подъёма.
class Wings : public Physic::PhysicObject {
	friend class Plane;

	const enum planeWings Name;

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

public:

	Wings(enum planeWings name, float coofBrake, float lCoof
                    , const char* fCollis, float m, float coof
					, Graphic::Shader& sh
                    , Graphic::Texture2D& tex
					, const glm::vec3& v3Pos = glm::vec3(0)
                    , const glm::vec3& v3Size = glm::vec3(1)
					, const glm::vec3& v3Speed = glm::vec3(0)); 

	virtual ~Wings() {}

};
}

#endif
