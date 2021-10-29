#include "body.h"

/*
Body::Body(PhysicObject& body, float fualSize) : 
						PhysicObject(body), fualTankSize(fualSize),
						curFuelQuantity(fualSize) {}
*/
Body::Body(enum planeBodies name, float fualSize, float m, float coof, 
					const Shader& sh, const Texture2D& tex, 
					const vec3& pos, const vec3& size,
					const vec3& speed) : 
				PhysicObject(m, coof, sh, tex, pos, size, speed),
				Name(name), fualTankSize(fualSize) {}

void Body::BurnFuel(float fuelConsumption)
{
	curFuelQuantity -= fuelConsumption;
}
