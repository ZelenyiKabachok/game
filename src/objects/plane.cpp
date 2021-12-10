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
	printf("DirAngle = %f\n", pTail->DirAngle);
	printf("PlaneAngle = %f\n", pTail->PlaneAngle);
	printf("Speed { %f; %f; 0 }\n", v3PlaneSpeed.x, v3PlaneSpeed.y);
	printf("Plane Position = { %f; %f; 0 }\n", pBody->v3Position.x
                                               , pBody->v3Position.y);
	printf("Plane Thust Force = { %f; %f; 0 }\n", pEngine->v3ThrustForce.x
								                , pEngine->v3ThrustForce.y);
	printf("Plane Boost ThrustForce = { %f; %f; 0.0 }\n" 
						, pEngine->v3PowerPulse.x, pEngine->v3PowerPulse.y);
	printf("Plane Lifting Force = { %f; %f; 0.0 }\n"
						, pWings->v3LiftingForce.x, pWings->v3LiftingForce.y);
//	printf("\n ----------------------------------------------------------------- \n");
}

void Aircraft::Plane::Render(const Camera& camera) const
{
	pBody->Graphic::GraphObject::Draw(camera);
	pEngine->Graphic::GraphObject::Draw(camera);
	pWings->Graphic::GraphObject::Draw(camera);
	pTail->Graphic::GraphObject::Draw(camera);
	pCollision->Draw(camera);
}

void Aircraft::Plane::Fly(float delta_time, bool gas, bool brake, float angle)
{
    //printf("\tUser Angle = %f\n", angle);
	v3PlaneSpeed = pBody->v3Speed;
	pTail->FindDirect(angle);
	pTail->FindAngle(v3PlaneSpeed);
	pEngine->Work(delta_time, pTail->DirAngle, gas, brake);
	pWings->CalcLiftForce(v3PlaneSpeed, pTail->PlaneAngle, gas, brake);
	pBody->BurnFuel(pEngine->fuelConsumption);

//Скорость, позиция, силы и т.д всего самолёта будут
//расчитываться объектом body.
//Он примет все харктеристики самолёта.
	glm::vec3 v3ResultantForce = pEngine->v3ThrustForce + pWings->v3LiftingForce;
	pBody->Move(delta_time, v3ResultantForce);
	pBody->Rotate(glm::vec3(0.0, 0.0, 1.0), pTail->PlaneAngle);


	ChangePosParts();
    //PrintPlaneState();
}		

void Aircraft::Plane::Build()
{
//	ChangePosParts();

    TotalWeight = 0;
	TotalWeight += pBody->mass;
	TotalWeight += pEngine->mass;
	TotalWeight += pWings->mass;
	TotalWeight += pTail->mass;

    AverResistCoof = 0;
	AverResistCoof += pBody->coofResistance;
	AverResistCoof += pEngine->coofResistance;
	AverResistCoof += pWings->coofResistance;
	AverResistCoof += pTail->coofResistance;
	AverResistCoof /= 4;	

	pBody->mass = TotalWeight;
	pBody->coofResistance = AverResistCoof;


}

void Aircraft::Plane::InitCollision(Physic::PCollisions& collObj)
{
	pCollision = collObj.Add(pBody->collision);
    pCollision->Join(pEngine->collision, pBody->StartEnginesPos[pEngine->Name]);
    pCollision->Join(pWings->collision, pBody->StartWingsPos[pWings->Name]);
    pCollision->Join(pTail->collision, pBody->StartTailsPos[pTail->Name]);
}

Aircraft::Plane::Plane(Aircraft::Body* body, Aircraft::Engine* engine
			    , Aircraft::Wings* wings, Aircraft::Tail *tail
			    , const glm::vec3& v3Pos, const glm::vec3& v3Speed
                , Physic::PCollisions& collObj)
				    : pBody(body), pEngine(engine), pWings(wings)
                    , pTail(tail), v3PlaneSpeed(v3Speed)
{
	pBody->v3Position = v3Pos;
	pBody->v3Speed = v3PlaneSpeed;
	InitCollision(collObj);
	Build();
}

const Aircraft::Body& Aircraft::Plane::GetBody() const
{
	return *pBody;
}

void Aircraft::Plane::StartDrawCollision()
{ pCollision->BeginDraw(); }
