#include "wings.h"

Wings::Wings(enum planeWings name, unsigned int nshapes,
					float coofBrake, float lCoof, float m, float coof, 
					const Shader& sh, const Texture2D& tex, 
					const vec3& pos, const vec3& size,
					const vec3& speed) : 
				PhysicObject(m, coof, sh, tex, pos, size, speed), 
				Name(name), num_shapes(nshapes),
				liftingCoof(lCoof), coofResBrake(coofBrake) {}

void Wings::CalcLiftForce(const vec3& PlaneSpeed, float PlaneAngle, bool gas, bool brake)
{
	mat4 RotateMatrix = glm::rotate(mat4(1.0),
						(float)(-(PlaneAngle+M_PI/2)), vec3(0.0, 0.0, 1.0));

	float speed = glm::length(liftingCoof*PlaneSpeed);
	liftingForce = vec3(glm::vec4(speed, 0.0, 0.0, 0.0) * RotateMatrix);
	
	if(brake) {
		coofResistance = coofResBrake;	
	} else {
		coofResistance = coofResNorm;
	}
}	

