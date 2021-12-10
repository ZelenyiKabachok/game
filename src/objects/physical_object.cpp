#include "physical_object.h"

void Physic::PhysicObject::Move(float delta_time, const glm::vec3& v3Force)
{
 	//Равнодействующая силы притяжения и остальных сил
    //, кроме силы сопротивления воздуха.
	glm::vec3 v3Resultant = v3Force + v3ForceOfAttract;
	//Сила сопротивления воздуха.
	glm::vec3 v3ResistanceForce = (-this->v3Speed) * coofResistance;

	//Равнодействующая всех сил.
	glm::vec3 v3FinalForce = v3Resultant + v3ResistanceForce;

	glm::vec3 v3Boost = v3FinalForce/mass; //Вектор ускорения.
	this->v3Speed += v3Boost * delta_time; 

	this->v3Position += this->v3Speed * delta_time;
	this->matPosition = glm::translate(glm::mat4(1.0f), this->v3Position);

//    printf("mass = %f\n", mass);
//   printf("Force { %f; %f; %f; }\n", v3Force.x, v3Force.y, v3Force.z);
//    printf("ForceOfAttract { %f; %f; %f}\n", v3ForceOfAttract.x, v3ForceOfAttract.y, v3ForceOfAttract.z);
//    printf("Resultant { %f; %f; %f }\n", v3Resultant.x, v3Resultant.y, v3Resultant.z);
 //   printf("Resistance { %f; %f; %f }\n", v3ResistanceForce.x, v3ResistanceForce.y, v3ResistanceForce.x);
  //  printf("Final { %f; %f; %f }\n", v3FinalForce.x, v3FinalForce.y, v3FinalForce.z);
   // printf("\n\n");
    collision.Movement(this->v3Position);
}

Physic::PhysicObject::PhysicObject(const char* fCollis, float m
                            , float coof, Graphic::Shader& sh 
			 	            , Graphic::Texture2D& tex
                            , const glm::vec3& v3Pos
				            , const glm::vec3& v3Size
                            , const glm::vec3& v3Speed
				            , const glm::vec3& v3Slant, const float angle)
					: GraphObject(sh, tex, v3Pos, v3Size
                                , v3Speed, v3Slant, angle)
					, mass(m), coofResistance(coof)
        , collision(ResourceManager::Instance().LoadCollision(fCollis))
{
    collision.Rotation(angle);
	v3ForceOfAttract.y = mass * -9.8;
}

void Physic::PhysicObject::StartDrawCollision()
{ collision.BeginDraw(); }

void Physic::PhysicObject::Draw(const Camera& camera)
{
    Graphic::GraphObject::Draw(camera);
    collision.Draw(camera);
}

Physic::PhysicObject::PhysicObject(const char* fCollis
                                 , float m, float coof
                                 , Graphic::GraphObject object)
				    : GraphObject(object)
                    , mass(m), coofResistance(coof)
        , collision(ResourceManager::Instance().LoadCollision(fCollis))
{
	v3ForceOfAttract.y = mass * -9.8;
}
