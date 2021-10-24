#include "body.h"

using namespace AircraftParts;

Body::Body(PhysicObject& body, float fualSize) : 
						PhysicObject(body), fualTankSize(fualSize),
						curFuelQuantity(fualSize) {}

void Body::BurnFuel(float fuelConsumption)
{
	curFuelQuantity -= fuelConsumption;
}
