#include "wings.h"

Wings::Wings(PhysicObject& wings, float coofBrake, float lCoof) : 
		PhysicObject(wings), liftingCoof(lCoof), coofResBrake(coofBrake) {}

void Wings::CalcLiftForce(const vec3& PlaneSpeed, bool gas, bool brake)
{
	liftingForce = liftingCoof * PlaneSpeed;
	if(brake) {
		coofResistance = coofResBrake;	
	} else {
		coofResistance = coofResNorm;
	}
}	

