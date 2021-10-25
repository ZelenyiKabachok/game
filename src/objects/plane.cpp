#include "plane.h"

void Plane::Fly(bool gas, bool brake, float angle)
{

}		

void Plane::Build()
{
	engine.ChangePosition(body.ObPosition + body.StartPartsPos[ENGINE]);
	wings.ChangePosition(body.ObPosition + body.StartPartsPos[WINGS]);
	tail.ChangePosition(body.ObPosition + body.StartPartsPos[TAIL]);

	TotalWeight += body.mass;
	TotalWeight += engine.mass;
	TotalWeight += wings.mass;
	TotalWeight += tail.mass;

	AverResistCoof += body.coofResistance;
	AverResistCoof += engine.coofResistance;
	AverResistCoof += wings.coofResistance;
	AverResistCoof += tail.coofResistance;
	AverResistCoof /= 4;	
}

Plane::Plane(Body& Abody, Engine& Aengine, Wings& Awing,
								Tail& Atail, float speed) :
			body(Abody), engine(Aengine), wings(Awing), tail(Atail), PlaneSpeed(speed)
{
	Build();
}

