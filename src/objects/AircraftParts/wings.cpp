#include "wings.h"

Aircraft::Wings::Wings(enum planeWings name, const char* fCollis
					, float coofBrake, float lCoof, float m, float coof
					, Graphic::Shader& sh
                    , Graphic::Texture2D& tex
					, const glm::vec3& v3Pos, const glm::vec3& v3Size
					, const glm::vec3& v3Speed)
			    : PhysicObject(m, coof, sh, tex, v3Pos, v3Size, v3Speed)
				, Name(name)
                , collision(ResourceManager::Instance().LoadCollision(fCollis))
				, liftingCoof(lCoof), coofResBrake(coofBrake) {}

void Aircraft::Wings::CalcLiftForce(const glm::vec3& v3PlaneSpeed
                                    , float PlaneAngle
                                    , bool gas, bool brake)
{
	glm::mat4 matRotate = glm::rotate(glm::mat4(1.0)
						    , (float)(-(PlaneAngle+M_PI/2))
                            , glm::vec3(0.0, 0.0, 1.0));

	float speed = glm::length(liftingCoof*v3PlaneSpeed);
	v3LiftingForce = glm::vec3(glm::vec4(speed, 0.0, 0.0, 0.0) * matRotate);
	
	if(brake) {
		coofResistance = coofResBrake;	
	} else {
		coofResistance = coofResNorm;
	}
}	

