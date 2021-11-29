#include "body.h"

Aircraft::Body::Body(enum planeBodies name, unsigned int nshapes, float fualSize
					 , float m, float coof
					 , const Graphic::Shader& sh, const Graphic::Texture2D& tex
					 , const glm::vec3& v3Pos, const glm::vec3& v3Size
					 , const glm::vec3& v3Speed) : 
				PhysicObject(m, coof, sh, tex, v3Pos, v3Size, v3Speed),
				Name(name), num_shapes(nshapes), fualTankSize(fualSize) {}

void Aircraft::Body::BurnFuel(float fuelConsumption)
{
	curFuelQuantity -= fuelConsumption;
}
