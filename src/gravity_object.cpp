#include "gravity_object.h"

void GravityObject::Attract(float delta_time)
{
	//float attract = ObSpeed.y/delta_time;
	float ForceOfAttract = mass * 9.8;
	float ResistanceForce = (-ObSpeed.y) * cooficient;
	float FinalForce = ForceOfAttract - ResistanceForce;
	float boost = FinalForce/mass;
	ObSpeed.y += (-boost) * delta_time;
//	ObSpeed.y -= 9.8 * delta_time;
	printf("Y Speed = %f\n", ObSpeed.y);
	
}
