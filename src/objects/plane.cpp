#include "plane.h"

void Aircraft::Plane::ChangePosParts()
{
	glm::mat4 matRotate = glm::rotate(glm::mat4(1.0), pTail->PlaneAngle
                                      , glm::vec3(0.0, 0.0, 1.0));

	pEngine->ChangePosition(pBody->v3Position + 
		glm::vec3(matRotate * glm::vec4(pBody->StartEnginesPos[pEngine->Name], 1.0)));
	pWings->ChangePosition(pBody->v3Position + 
		glm::vec3(matRotate * glm::vec4(pBody->StartWingsPos[pWings->Name], 1.0)));
	pTail->ChangePosition(pBody->v3Position + 
		glm::vec3(matRotate * glm::vec4(pBody->StartTailsPos[pTail->Name], 1.0)));

	pEngine->Rotate(glm::vec3(0.0, 0.0, 1.0), pTail->PlaneAngle);
	pWings->Rotate(glm::vec3(0.0, 0.0, 1.0), pTail->PlaneAngle);
	pTail->Rotate(glm::vec3(0.0, 0.0, 1.0), pTail->PlaneAngle);
	pCollision->Movement(pBody->v3Position);
	pCollision->Rotation(pTail->PlaneAngle);
}

void Aircraft::Plane::PrintPlaneState() const
{
//	printf("DirAngle = %f\n", pTail->DirAngle);
	printf("PlaneAngle = %f\n\n", pTail->PlaneAngle);
	printf("Speed { %f; %f; 0 }\n", v3PlaneSpeed.x, v3PlaneSpeed.y);
	printf("Plane Position = { %f; %f; 0 }\n\n", pBody->v3Position.x
                                               , pBody->v3Position.y);
	printf("Plane Thust Force = { %f; %f; 0 }\n", pEngine->v3ThrustForce.x
								                , pEngine->v3ThrustForce.y);
	printf("Plane Boost ThrustForce = { %f; %f; 0.0 }\n" 
						, pEngine->v3PowerPulse.x, pEngine->v3PowerPulse.y);
	printf("Plane Lifting Force = { %f; %f; 0.0 }\n"
						, pWings->v3LiftingForce.x, pWings->v3LiftingForce.y);
	printf("\n ----------------------------------------------------------------- \n");
}

void Aircraft::Plane::Render(const Camera& camera) const
{
	pBody->Draw(camera);
	pEngine->Draw(camera);
	pWings->Draw(camera);
	pTail->Draw(camera);
	pCollision->Draw(camera);
}

void Aircraft::Plane::Fly(float delta_time, bool gas, bool brake, float angle)
{
 //   printf("\tUser Angle = %f\n", angle);
	v3PlaneSpeed = pBody->v3Speed;
	pTail->FindDirect(angle);
	pTail->FindAngle(v3PlaneSpeed);
	pEngine->Work(delta_time, pTail->DirAngle, gas, brake);
	pWings->CalcLiftForce(v3PlaneSpeed, pTail->PlaneAngle, gas, brake);
	pBody->BurnFuel(pEngine->fuelConsumption);

//Скорость, позиция, силы и т.д всего самолёта будут
//расчитываться объектом body.
//Он примет все харктеристики самолёта.
	pBody->mass = TotalWeight;
	pBody->coofResistance = AverResistCoof;

	glm::vec3 v3ResultantForce = pEngine->v3ThrustForce + pWings->v3LiftingForce;
	pBody->AttractAndMove(delta_time, v3ResultantForce);
	pBody->Rotate(glm::vec3(0.0, 0.0, 1.0), pTail->PlaneAngle);


	ChangePosParts();
    PrintPlaneState();
}		

void Aircraft::Plane::Build()
{
	ChangePosParts();

	TotalWeight += pBody->mass;
	TotalWeight += pEngine->mass;
	TotalWeight += pWings->mass;
	TotalWeight += pTail->mass;

	AverResistCoof += pBody->coofResistance;
	AverResistCoof += pEngine->coofResistance;
	AverResistCoof += pWings->coofResistance;
	AverResistCoof += pTail->coofResistance;
	AverResistCoof /= 4;	
}

void Aircraft::Plane::InitCollision(Physic::PCollisions& collObj)
{
	unsigned int max_shapes = 0;
	max_shapes += pBody->num_shapes;	
	max_shapes += pEngine->num_shapes;
	max_shapes += pWings->num_shapes;
	max_shapes += pTail->num_shapes;

	Physic::Shape** shapes = new Physic::Shape*[max_shapes];
	unsigned int pos = 0;
	pBody->GetShapes(shapes, pos);
	pEngine->GetShapes(shapes, pos);
	pWings->GetShapes(shapes, pos);
	pTail->GetShapes(shapes, pos);

	pCollision = collObj.Add(shapes, max_shapes);

	for(unsigned int i = 0; i < max_shapes; i++) {
		delete shapes[i];
	}
	delete[] shapes;
}

Aircraft::Plane::Plane(planeBodies body_name, planeEngines engine_name
			    , planeWings wings_name, planeTails tail_name
			    , const glm::vec3& v3Pos, const glm::vec3& v3Speed
                , Physic::PCollisions& collObj
			    , const Graphic::Shader& planeShader)
				    : shader(planeShader), v3PlaneSpeed(v3Speed)
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
	pBody->v3Position = v3Pos;
	pBody->v3Speed = v3PlaneSpeed;
	InitCollision(collObj);
	Build();
}

Aircraft::Plane::~Plane()
{
	delete pBody;
	delete pEngine;
	delete pWings;
	delete pTail;
}

const Aircraft::Body& Aircraft::Plane::GetBody() const
{
	return *pBody;
}

void Aircraft::Plane::InitBody(planeBodies body_name, float *vertexes
                                                , unsigned int *indices)
{
	switch(body_name) {
	case RUST_BODY:
		pBody = new RustyBody(shader);
	}
    pBody->initShaderData(vertexes, indices, 20, 6);
}

void Aircraft::Plane::InitEngine(planeEngines engine_name, float *vertexes
                                                , unsigned int *indices)
{
	switch(engine_name) {
	case RUST_ENGINE:
		pEngine = new RustyEngine(shader);
	}
	pEngine->initShaderData(vertexes, indices, 20, 6);
}

void Aircraft::Plane::InitWings(planeWings wings_name, float *vertexes
                                                , unsigned int *indices)
{
	switch(wings_name) {
	case RUST_WINGS:
		pWings = new RustyWings(shader);
	}
	pWings->initShaderData(vertexes, indices, 20, 6);
}

void Aircraft::Plane::InitTail(planeTails tail_name, float *vertexes
                                                , unsigned int *indices)
{
	switch(tail_name) {
	case RUST_TAIL:
		pTail = new RustyTail(shader);
	}
	pTail->initShaderData(vertexes, indices, 20, 6);
}

void Aircraft::Plane::InitDrawColl(Graphic::Shader coll
                                    , Graphic::Shader aabb
                                    , Graphic::Texture2D collTex)
{ pCollision->BeginDraw(coll, aabb, collTex); }
