#include "plane.h"

Plane::Plane(Body& Abody, Engine& Aengine, Wings& Awing,
										Tail& Atail, float speed) :
			body(Abody), engine(Aengine), wing(Awing), tail(Atail), PlaneSpeed(speed)
{}
	
