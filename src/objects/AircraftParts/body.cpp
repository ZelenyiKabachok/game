#include "body.h"

Body::Body(PhysicObject& body, float fualSize, vec3 *parts) : 
						PhysicObject(body), fualTankSize(fualSize),
						curFuelQuantity(fualSize)
{
	for(int i = 0; i <= 2; i++) {
		StartPartsPos[i] = parts[i];
	}
}

vec3 Body::GetPartPos(enum planeParts part)
{
	return StartPartsPos[part];
}

void Body::BurnFuel(float fuelConsumption)
{
	curFuelQuantity -= fuelConsumption;
}
