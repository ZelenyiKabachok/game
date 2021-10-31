#include "tail.h"

Tail::Tail(enum planeTail name, float DirAlpha, float m, float coof, 
					const Shader& sh, const Texture2D& tex, 
					const vec3& pos, const vec3& size,
					const vec3& speed) : 
				PhysicObject(m, coof, sh, tex, pos, size, speed), 
				Name(name), DirAngle(DirAlpha) {}

void Tail::FindDirect(float alpha)
{
	DirAngle += alpha;

	if(DirAngle > M_PI/2)  { DirAngle = M_PI/2; }
	if(DirAngle < -M_PI/2) { DirAngle = -M_PI/2; }

	direction.x = cos(DirAngle);
	direction.y = sin(DirAngle);

}

void Tail::FindAngle(vec3 PlaneSpeed)
{
	PlaneAngle = acos((PlaneSpeed.x)/
		(sqrt(PlaneSpeed.x*PlaneSpeed.x + PlaneSpeed.y*PlaneSpeed.y + 
			  							PlaneSpeed.z*PlaneSpeed.z)));
	if(PlaneSpeed.y < 0) { PlaneAngle *= -1; }
}	
