#ifndef WINGS_H
#define WINGS_H

#include "../physical_object.h"

enum planeWings { RustWings };

//Крылья самолёта.
//Расчитывает силу подъёма.
class Wings : public PhysicObject {
	friend class Plane;

	const enum planeWings Name;
//Коэфициент силы подъёма, чем больше тем быстрее поднимает высоту.
	const float liftingCoof;
//Коэфициент сопротивления воздуха при торможении.
	const float coofResBrake;
//Коэфициент сопротивления воздуха в обычном состоянии.
	const float coofResNorm = coofResistance;

//Подъёмная сила.
	vec3 liftingForce = liftingCoof * ObSpeed;

//Меняет коэфициент силы сопротивления воздуха.
//При торможении coofResistance устанавливается в coofResBrake.
	void CalcLiftForce(const vec3& PlaneSpeed, bool gas, bool brake);

public:

	Wings(enum planeWings name, float coofBrake, float lCoof, float m, float coof, 
					const Shader& sh, const Texture2D& tex, 
					const vec3& pos = vec3(0), const vec3& size = vec3(1),
					const vec3& speed = vec3(0)); 
};

#endif
