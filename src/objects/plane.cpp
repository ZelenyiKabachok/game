#include "plane.h"

void Plane::ChangePosParts()
{
	glm::mat4 RotateMatrix = glm::rotate(mat4(1.0), tail->PlaneAngle, vec3(0.0, 0.0, 1.0));

	engine->ChangePosition(body->ObPosition + 
		vec3(RotateMatrix * glm::vec4(body->StartEnginesPos[engine->Name], 1.0)));
	wings->ChangePosition(body->ObPosition + 
		vec3(RotateMatrix * glm::vec4(body->StartWingsPos[wings->Name], 1.0)));
	tail->ChangePosition(body->ObPosition + 
		vec3(RotateMatrix * glm::vec4(body->StartTailsPos[tail->Name], 1.0)));

	engine->Rotate(vec3(0.0, 0.0, 1.0), tail->PlaneAngle);
	wings->Rotate(vec3(0.0, 0.0, 1.0), tail->PlaneAngle);
	tail->Rotate(vec3(0.0, 0.0, 1.0), tail->PlaneAngle);
	collision->Movement(body->ObPosition);
	collision->Rotation(tail->PlaneAngle);
}

void Plane::PrintPlaneState() const
{
	printf("DirAngle = %f\n", tail->DirAngle);
	printf("PlaneAngle = %f\n\n", tail->PlaneAngle);
	printf("Speed { %f; %f; %f }\n", PlaneSpeed.x, PlaneSpeed.y, PlaneSpeed.z);
	printf("Plane Position = { %f; %f; 0 }\n\n", body->ObPosition.x, body->ObPosition.y);
	printf("Plane Thust Force = { %f; %f; %f }\n", engine->ThrustForce.x, 
								engine->ThrustForce.y, engine->ThrustForce.z);
	printf("Plane Boost ThrustForce = { %f; %f; 0.0 }\n", 
						engine->PowerPulse.x, engine->PowerPulse.y);
	printf("Plane Lifting Force = { %f; %f; 0.0 }\n",
						wings->liftingForce.x, wings->liftingForce.y);
	printf("\n ----------------------------------------------------------------- \n");
}

void Plane::Render(const Camera& camera) const
{
	body->Draw(camera);
	engine->Draw(camera);
	wings->Draw(camera);
	tail->Draw(camera);
	collision->Draw(camera);
}

void Plane::Fly(float delta_time, bool gas, bool brake, float angle)
{
	PlaneSpeed = body->ObSpeed;
	tail->FindDirect(angle);
	tail->FindAngle(PlaneSpeed);
	engine->Work(delta_time, tail->DirAngle, gas, brake);
	wings->CalcLiftForce(PlaneSpeed, tail->PlaneAngle, gas, brake);
	body->BurnFuel(engine->fuelConsumption);

//Скорость, позиция, силы и т.д всего самолёта будут
//расчитываться объектом body.
//Он примет все харктеристики самолёта.
	body->mass = TotalWeight;
	body->coofResistance = AverResistCoof;

	vec3 ResultantForce = engine->ThrustForce + wings->liftingForce;
	body->AttractAndMove(delta_time, ResultantForce,
						vec3(0.0, 0.0, 1.0), tail->PlaneAngle);


	ChangePosParts();
}		

void Plane::Build()
{
	ChangePosParts();

	TotalWeight += body->mass;
	TotalWeight += engine->mass;
	TotalWeight += wings->mass;
	TotalWeight += tail->mass;

	AverResistCoof += body->coofResistance;
	AverResistCoof += engine->coofResistance;
	AverResistCoof += wings->coofResistance;
	AverResistCoof += tail->coofResistance;
	AverResistCoof /= 4;	
}

void Plane::InitCollision(PCollisions& collObj)
{
	unsigned int max_shapes = 0;
	max_shapes += body->num_shapes;	
	max_shapes += engine->num_shapes;
	max_shapes += wings->num_shapes;
	max_shapes += tail->num_shapes;

	Shape** const shapes = new Shape*[max_shapes];
	unsigned int pos = 0;
	body->GetShapes(shapes, pos);
	engine->GetShapes(shapes, pos);
	wings->GetShapes(shapes, pos);
	tail->GetShapes(shapes, pos);

	collision = collObj.Add(shapes, max_shapes);
//	collision->PrepareForDraw();

	for(unsigned int i = 0; i < max_shapes; i++) {
		delete shapes[i];
	}
	delete[] shapes;
}

Plane::Plane(planeBodies body_name, planeEngines engine_name,
			 planeWings wings_name, planeTails tail_name,
			 const vec3& pos, const vec3& speed, PCollisions& collObj,
			 const Shader& planeShader)
				: shader(planeShader), PlaneSpeed(speed)
{
	float vertexes[] = { 
       -1.0, -1.0, 0.0,     0.0, 0.0, 
       -1.0,  1.0, 0.0,     0.0, 1.0, 
        1.0,  1.0, 0.0,     1.0, 1.0, 
        1.0, -1.0, 0.0,     1.0, 0,0 
    }; 
    unsigned int indices[] { 
        0, 1, 2, 
        0, 2, 3 
    }; 

	InitBody(body_name, vertexes, indices);
	InitEngine(engine_name, vertexes, indices);
	InitWings(wings_name, vertexes, indices);
	InitTail(tail_name, vertexes, indices);
	body->ObPosition = pos;
	body->ObSpeed = PlaneSpeed;

	InitCollision(collObj);
	Build();
}

Plane::~Plane()
{
	delete body;
	delete engine;
	delete wings;
	delete tail;
}

const Body& Plane::GetBody() const
{
	return *body;
}

void Plane::InitBody(planeBodies body_name, float *vertexes, unsigned int *indices)
{
	switch(body_name) {
	case RUST_BODY:
		body = new RustyBody(shader);
	}
    body->initShaderData(vertexes, indices, 20, 6);
}

void Plane::InitEngine(planeEngines engine_name, float *vertexes, unsigned int *indices)
{
	switch(engine_name) {
	case RUST_ENGINE:
		engine = new RustyEngine(shader);
	}
	engine->initShaderData(vertexes, indices, 20, 6);
}

void Plane::InitWings(planeWings wings_name, float *vertexes, unsigned int *indices)
{
	switch(wings_name) {
	case RUST_WINGS:
		wings = new RustyWings(shader);
	}
	wings->initShaderData(vertexes, indices, 20, 6);
}

void Plane::InitTail(planeTails tail_name, float *vertexes, unsigned int *indices)
{
	switch(tail_name) {
	case RUST_TAIL:
		tail = new RustyTail(shader);
	}
	tail->initShaderData(vertexes, indices, 20, 6);
}
