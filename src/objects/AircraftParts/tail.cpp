#include "tail.h"

Tail::Tail(PhysicObject& tail, float alpha) :
			PhysicObject(tail), angle(alpha) {}

void Tail::SetDirect(float alpha)
{
	angle += alpha;

	if(angle > M_PI/2)  { angle = M_PI/2; }
	if(angle < -M_PI/2) { angle = -M_PI/2; }

	printf("Angle = %f\n", angle);

	direction.x = cos(angle);
	direction.y = sin(angle);
}
