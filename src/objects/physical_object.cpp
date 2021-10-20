#include "physical_object.h"

void GravityObject::Attract(float delta_time, const vec3& Force) 
{
	vec3 ForceOfAttract;
	ForceOfAttract.y = mass * -9.8;
	vec3 Resultant = Force + ForceOfAttract;
	vec3 ResistanceForce = (-ObSpeed) * cooficient;
	vec3 FinalForce = Resultant + ResistanceForce;
	vec3 boost = FinalForce/mass;
	ObSpeed += boost * delta_time;

	printf("Speed = { %f; %f; %f }\n", ObSpeed.x, ObSpeed.y, ObSpeed.z);
	printf("Boost = { %f; %f; %f }\n", boost.x, boost.y, boost.z);
	printf("Force Of Attarect.y = %f\n", ForceOfAttract.y);
	printf("In Force = { %f; %f; %f }\n", Force.x, Force.y, Force.z);
	printf("Resultant Force = { %f; %f; %f }\n", Resultant.x, Resultant.y, Resultant.z);
	printf("Resistance Force = { %f; %f; %f }\n", ResistanceForce.x, ResistanceForce.y,
																	ResistanceForce.z);	
	printf("Final Force = { %f; %f; %f }\n", FinalForce.x, FinalForce.y, FinalForce.z);
	printf("\n");

}
