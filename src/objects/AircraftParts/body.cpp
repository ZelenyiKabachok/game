#include "body.h"

Aircraft::Body::Body(enum planeBodies name, const char* fCollis
                     , float fual, float m, float coof
					 , Graphic::Shader& sh, Graphic::Texture2D& tex
					 , const glm::vec3& v3Pos, const glm::vec3& v3Size
					 , const glm::vec3& v3Speed) 
				: PhysicObject(m, coof, sh, tex, v3Pos, v3Size, v3Speed)
				, Name(name)
                , collision(ResourceManager::Instance().LoadCollision(fCollis))
                , fualTankSize(fual) {}

void Aircraft::Body::BurnFuel(float fuelConsumption)
{
	curFuelQuantity -= fuelConsumption;
}
