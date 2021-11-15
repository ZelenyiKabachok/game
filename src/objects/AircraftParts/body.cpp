#include "body.h"

Body::Body(enum planeBodies name, unsigned int nshapes, float fualSize,
					float m, float coof, 
					const Shader& sh, const Texture2D& tex, 
					const vec3& pos, const vec3& size,
					const vec3& speed) : 
				PhysicObject(m, coof, sh, tex, pos, size, speed),
				Name(name), num_shapes(nshapes), fualTankSize(fualSize) {}

void Body::BurnFuel(float fuelConsumption)
{
	curFuelQuantity -= fuelConsumption;
}
