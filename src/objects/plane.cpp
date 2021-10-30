#include "plane.h"

void Plane::ChangePosParts()
{

	engine.ChangePosition(body.ObPosition + body.StartEnginesPos[RustEngine]);
	wings.ChangePosition(body.ObPosition + body.StartWingsPos[RustWings]);
	tail.ChangePosition(body.ObPosition + body.StartTailsPos[RustTail]);

	engine.Move(0.0);
	wings.Move(0.0);
	tail.Move(0.0);
/*
	engine.ObPosition = body.ObPosition + body.StartEnginesPos[RustEngine];
	engine.ObPosition.x = 5.0;
	printf("Pos body = { %f; %f; %f; }\n", engine.ObPosition.x, engine.ObPosition.y ,engine.ObPosition.z);
*/
}

void Plane::Render() const
{
	body.Draw();
	engine.Draw();
	wings.Draw();
	tail.Draw();
}

void Plane::Fly(float delta_time, bool gas, bool brake, float angle)
{
	tail.FindDirect(angle);
//	engine.Work(delta_time, tail.direction, gas, brake);
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

void Plane::Init()
{
    float Position[] = { 
       -1.0, -1.0, 0.0,     0.0, 0.0, 
       -1.0,  1.0, 0.0,     0.0, 1.0, 
        1.0,  1.0, 0.0,     1.0, 1.0, 
        1.0, -1.0, 0.0,     1.0, 0,0 
    }; 
    unsigned int Indices[] { 
        0, 1, 2, 
        0, 2, 3 
    }; 

	body.initShaderData(Position, Indices, 20, 6);
	engine.initShaderData(Position, Indices, 20, 6);
	wings.initShaderData(Position, Indices, 20, 6);
	tail.initShaderData(Position, Indices, 20, 6);

}

Plane::Plane(const Body& Abody, const Engine& Aengine, const Wings& Awing,
								const Tail& Atail, const vec3& speed) :
			body(Abody), engine(Aengine), wings(Awing), tail(Atail), PlaneSpeed(speed)
{

	Build();
	Init();
}

