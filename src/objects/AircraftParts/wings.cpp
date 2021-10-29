#include "wings.h"

Wings::Wings(enum planeWings name, float coofBrake, float lCoof, float m, float coof, 
					const Shader& sh, const Texture2D& tex, 
					const vec3& pos, const vec3& size,
					const vec3& speed) : 
				PhysicObject(m, coof, sh, tex, pos, size, speed), 
				Name(name), liftingCoof(lCoof), coofResBrake(coofBrake) {}

void Wings::CalcLiftForce(const vec3& PlaneSpeed, bool gas, bool brake)
{
	liftingForce = liftingCoof * PlaneSpeed;
	if(brake) {
		coofResistance = coofResBrake;	
	} else {
		coofResistance = coofResNorm;
	}
}	

