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

/*
	printf("Speed = { %f; %f; %f }\n", ObSpeed.x, ObSpeed.y, ObSpeed.z);
	printf("Boost = { %f; %f; %f }\n", boost.x, boost.y, boost.z);
	printf("Force Of Attaract = %f\n", ForceOfAttract);
	printf("In Force = { %f; %f; %f }\n", Force.x, Force.y, Force.z);
	printf("Resultant Force = { %f; %f; %f }\n", Resultant.x, Resultant.y, Resultant.z);
	printf("Resistance Force = { %f; %f; %f }\n", ResistanceForce.x, ResistanceForce.y,
																	ResistanceForce.z);	
	printf("Final Force = { %f; %f; %f }\n", FinalForce.x, FinalForce.y, FinalForce.z);
	printf("\n");
*/

	Move(delta_time, rotateVec, angle);
}

PhysicObject::PhysicObject(float m, float coof, const Shader& sh, 
					const Texture2D& tex, const vec3& pos,
					const vec3& size, const vec3& speed) : 
					GraphObject(sh, tex, pos, size, speed), mass(m), 
					coofResistance(coof)
{
	ForceOfAttract.y = mass * -9.8;
}

PhysicObject::PhysicObject(float m, float coof, GraphObject object) :
						GraphObject(object), mass(m), coofResistance(coof)
{
	ForceOfAttract.y = mass * -9.8;
}
