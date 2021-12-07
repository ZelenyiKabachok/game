#ifndef BODY_H
#define BODY_H

#include "../physical_object.h"

namespace Aircraft {

enum planeBodies { RUST_BODY };

//Корпус для самолёта.
//Содержит информация о количестве топлива.
class Body : public Physic::PhysicObject {
	friend class Plane;

	const enum planeBodies Name;

//Максимальный объём топливного бака
	const float fualTankSize;

//Текущий объём топливного бака 
	float curFuelQuantity;
	
	float bodyCoofResis;//Коэфициент сопротивление воздуха.
	float bodyMass; 	//Вес корпуса самолёта.

//Расположение всех существующий частей самолёта относительно копруса.
protected:
	glm::vec3 StartEnginesPos[1];
	glm::vec3 StartWingsPos[1];
	glm::vec3 StartTailsPos[1];

private:
//Сжегает топливо.
	void BurnFuel(float fuelConsumption);

public:

	Body(enum planeBodies name, float fual, const char* fCollis
                    , float m, float coof
					, Graphic::Shader& sh, Graphic::Texture2D& tex
					, const glm::vec3& v3Pos = glm::vec3(0)
                    , const glm::vec3& v3Size = glm::vec3(1)
					, const glm::vec3& v3Speed = glm::vec3(0));
	
	virtual ~Body() {}

};
}

#endif
