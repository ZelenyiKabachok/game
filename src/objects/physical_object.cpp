#include "physical_object.h"

void Physic::PhysicObject::Move(float delta_time 
                                , const glm::vec3& v3Force)
{
 	//Равнодействующая силы притяжения и остальных сил, кроме силы сопротивления воздуха.
	glm::vec3 v3Resultant = v3Force + v3ForceOfAttract;

	//Сила сопротивления воздуха.
	glm::vec3 v3ResistanceForce = (-this->v3Speed) * coofResistance;

	//Равнодействующая всех сил.
	glm::vec3 v3FinalForce = v3Resultant + v3ResistanceForce;

	glm::vec3 v3Boost = v3FinalForce/mass; //Вектор ускорения.
	this->v3Speed += v3Boost * delta_time; 

	this->v3Position += this->v3Speed * delta_time;
	this->matPosition = glm::translate(glm::mat4(1.0f), this->v3Position);

}

Physic::PhysicObject::PhysicObject(float m, float coof
                , Graphic::Shader& sh 
			 	, Graphic::Texture2D& tex
                , const glm::vec3& v3Pos
				, const glm::vec3& v3Size
                , const glm::vec3& v3Speed
				, const glm::vec3& v3Slant, const float angle)
					: GraphObject(sh, tex, v3Pos, v3Size, v3Speed, v3Slant
                                                                   , angle)
					, mass(m), coofResistance(coof)
{
	v3ForceOfAttract.y = mass * -9.8;
}

Physic::PhysicObject::PhysicObject(float m, float coof
                        , Graphic::GraphObject object)
						    : GraphObject(object)
                            , mass(m), coofResistance(coof)
{
	v3ForceOfAttract.y = mass * -9.8;
}
