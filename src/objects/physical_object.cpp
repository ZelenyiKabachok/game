#include "physical_object.h"

void PhysicObject::AttractAndMove(float delta_time, const vec3& Force,
							const vec3& rotateVec, const float angle) 
{
 	//Равнодействующая силы притяжения и остальных сил, кроме силы сопротивления воздуха.
	vec3 Resultant = Force + ForceOfAttract;

	//Сила сопротивления воздуха.
	vec3 ResistanceForce = (-ObSpeed) * coofResistance;

	//Равнодействующая всех сил.
	vec3 FinalForce = Resultant + ResistanceForce;

	vec3 boost = FinalForce/mass; //Вектор ускорения.
	ObSpeed += boost * delta_time; 

	Move(delta_time, rotateVec, angle);
}

PhysicObject::PhysicObject(float m, float coof, const Shader& sh, 
					const Texture2D& tex, const vec3& pos,
					const vec3& size, const vec3& speed) : 
					GraphObject(sh, tex, pos, size, speed), mass(m), 
					coofResistance(coof) {}

float PhysicObject::GetMass() { return mass; }
float PhysicObject::GetCoof() { return coofResistance; }
