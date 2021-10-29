#include "tail.h"

Tail::Tail(enum planeTail name, float alpha, float m, float coof, 
					const Shader& sh, const Texture2D& tex, 
					const vec3& pos, const vec3& size,
					const vec3& speed) : 
				PhysicObject(m, coof, sh, tex, pos, size, speed), 
				Name(name), angle(alpha) {}

void Tail::FindDirect(float alpha)
{
	angle += alpha;

	if(angle > M_PI/2)  { angle = M_PI/2; }
	if(angle < -M_PI/2) { angle = -M_PI/2; }

	printf("Angle = %f\n", angle);

	direction.x = cos(angle);
	direction.y = sin(angle);
}
