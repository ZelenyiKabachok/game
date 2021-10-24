#include "wings.h"

using namespace AircraftParts;

Wings::Wings(PhysicObject& wings, float coofBrake, float lCoof) : 
		PhysicObject(wings), liftingCoof(lCoof), coofResBrake(coofBrake) {}

void Wings::Fly(bool gas, bool brake)
{
	liftingForce = liftingCoof * ObSpeed;
	if(brake) {
		coofResistance = coofResBrake;	
	} else {
		coofResistance = coofResNorm;
	}
}	

