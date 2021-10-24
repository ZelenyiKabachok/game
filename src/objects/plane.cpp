#include "plane.h"

void Plane::Build()
{
	engine.ChangePosition(body.StartPartsPos[ENGINE]);
	wings.ChangePosition(body.StartPartsPos[WINGS]);
	tail.ChangePosition(body.StartPartsPos[TAIL]);
}

Plane::Plane(Body& Abody, Engine& Aengine, Wings& Awing,
										Tail& Atail, float speed) :
			body(Abody), engine(Aengine), wings(Awing), tail(Atail), PlaneSpeed(speed)
{
	Build();
}

