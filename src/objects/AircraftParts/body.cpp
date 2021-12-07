#include "body.h"

Aircraft::Body::Body(enum planeBodies name, float fual
                     , const char* fCollis, float m, float coof
					 , Graphic::Shader& sh, Graphic::Texture2D& tex
					 , const glm::vec3& v3Pos, const glm::vec3& v3Size
					 , const glm::vec3& v3Speed) 
				: PhysicObject(fCollis, m, coof, sh, tex
                             , v3Pos, v3Size, v3Speed)
				, Name(name), fualTankSize(fual) {}

void Aircraft::Body::BurnFuel(float fuelConsumption)
{
	curFuelQuantity -= fuelConsumption;
}
