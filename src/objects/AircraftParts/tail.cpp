#include "tail.h"

using namespace AircraftParts;

Tail::Tail(PhysicObject& tail, float mAngle, float ang) :
			PhysicObject(tail), maxAngle(mAngle), angle(ang) {}

void Tail::SetDirect()
{
	direction.x = cos(angle);
	direction.y = sin(angle);
}
