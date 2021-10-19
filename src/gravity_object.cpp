#include "gravity_object.h"

void GravityObject::Attract(float delta_time)
{
	//float attract = ObSpeed.y/delta_time;
	vec3 ForceOfAttract;
	ForceOfAttract.y = mass * 9.8;
	vec3 ResistanceForce = (-ObSpeed) * cooficient;
	vec3 FinalForce = ForceOfAttract - ResistanceForce;
	vec3 boost = FinalForce/mass;
	ObSpeed += (-boost) * delta_time;
//	ObSpeed.y -= 9.8 * delta_time;
	printf("X Speed = %f, Y Speed = %f, Z Speed = %f\n", ObSpeed.x, ObSpeed.y, ObSpeed.z);
	
}
