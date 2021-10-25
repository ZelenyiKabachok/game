#include "plane.h"

void Plane::ChangePosParts()
{
	engine.ChangePosition(body.ObPosition + body.StartPartsPos[ENGINE]);
	wings.ChangePosition(body.ObPosition + body.StartPartsPos[WINGS]);
	tail.ChangePosition(body.ObPosition + body.StartPartsPos[TAIL]);
}

void Plane::Fly(float delta_time, bool gas, bool brake, float angle)
{
	tail.FindDirect(angle);
	engine.Work(delta_time, tail.direction, gas, brake);
	wings.CalcLiftForce(PlaneSpeed, gas, brake);
	body.BurnFuel(engine.fuelConsumption);

//Скорость, позиция, силы и т.д всего самолёта будут
//расчитываться объектом body.
//Он примет все харктеристики самолёта.
	body.mass = TotalWeight;
	body.coofResistance = AverResistCoof;

	vec3 ResultantForce = engine.ThrustForce + wings.liftingForce;
	body.AttractAndMove(delta_time, ResultantForce);
	ChangePosParts();
}		

void Plane::Build()
{
	ChangePosParts();

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
								Tail& Atail, vec3 speed) :
			body(Abody), engine(Aengine), wings(Awing), tail(Atail), PlaneSpeed(speed)
{
	Build();
}

