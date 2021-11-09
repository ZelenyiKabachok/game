#include "plane.h"

void Plane::ChangePosParts()
{
	glm::mat4 RotateMatrix = glm::rotate(mat4(1.0), tail.PlaneAngle, vec3(0.0, 0.0, 1.0));

	engine.ChangePosition(body.ObPosition + 
		vec3(RotateMatrix * glm::vec4(body.StartEnginesPos[engine.Name], 1.0)));
	wings.ChangePosition(body.ObPosition + 
		vec3(RotateMatrix * glm::vec4(body.StartWingsPos[wings.Name], 1.0)));
	tail.ChangePosition(body.ObPosition + 
		vec3(RotateMatrix * glm::vec4(body.StartTailsPos[tail.Name], 1.0)));

	engine.Rotate(vec3(0.0, 0.0, 1.0), tail.PlaneAngle);
	wings.Rotate(vec3(0.0, 0.0, 1.0), tail.PlaneAngle);
	tail.Rotate(vec3(0.0, 0.0, 1.0), tail.PlaneAngle);
}

void Plane::PrintPlaneState() const
{
	printf("DirAngle = %f\n", tail.DirAngle);
	printf("PlaneAngle = %f\n", tail.PlaneAngle);
	printf("Speed { %f; %f; %f }\n\n", PlaneSpeed.x, PlaneSpeed.y, PlaneSpeed.z);
	printf("Plane Thust Force = { %f; %f; %f }\n", engine.ThrustForce.x, 
								engine.ThrustForce.y, engine.ThrustForce.z);
	printf("Plane Boost ThrustForce = { %f; %f; 0.0 }\n", 
						engine.PowerPulse.x, engine.PowerPulse.y);
	printf("Plane Lifting Force = { %f; %f; 0.0 }\n",
						wings.liftingForce.x, wings.liftingForce.y);
	printf("\n ----------------------------------------------------------------- \n");
}

void Plane::Render(const Camera& camera) const
{
	body.Draw(camera);
	engine.Draw(camera);
	wings.Draw(camera);
	tail.Draw(camera);
}

void Plane::Fly(float delta_time, bool gas, bool brake, float angle)
{
	PlaneSpeed = body.ObSpeed;
	tail.FindDirect(angle);
	tail.FindAngle(PlaneSpeed);
	engine.Work(delta_time, tail.DirAngle, gas, brake);
	wings.CalcLiftForce(PlaneSpeed, tail.PlaneAngle, gas, brake);
	body.BurnFuel(engine.fuelConsumption);

//Скорость, позиция, силы и т.д всего самолёта будут
//расчитываться объектом body.
//Он примет все харктеристики самолёта.
	body.mass = TotalWeight;
	body.coofResistance = AverResistCoof;

	vec3 ResultantForce = engine.ThrustForce + wings.liftingForce;
	body.AttractAndMove(delta_time, ResultantForce,
						vec3(0.0, 0.0, 1.0), tail.PlaneAngle);
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
			 const Tail& Atail, const vec3& pos, const vec3& speed) :
			body(Abody), engine(Aengine), wings(Awing), tail(Atail), PlaneSpeed(speed)
{
	body.ObPosition = pos;
	body.ObSpeed = PlaneSpeed;
//	Shape forms[4] = { body.
//	collision(
	Build();
	Init();
}

const Body& Plane::GetBody() const
{
	return body;
}
