#include "plane.h"

Plane::Plane(PlaneBody& Abody, PlaneEngine& Aengine, PlaneWing& Awing,
										PlaneTail& Atail, float speed) :
			body(Abody), engine(Aengine), wing(Awing), tail(Atail), PlaneSpeed(speed)
{}
	
