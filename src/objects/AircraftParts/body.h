#ifndef BODY_H
#define BODY_H

#include "../physical_object.h"
#include "../shape.h"

namespace Aircraft {

enum planeBodies { RUST_BODY };

//Корпус для самолёта.
//Содержит информация о количестве топлива.
class Body : public Physic::PhysicObject {
	friend class Plane;

	const enum planeBodies Name;
	const unsigned int num_shapes; //количество фигур самолёта для коллизии.

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

	virtual void GetShapes(Physic::Shape** ppPlaneShapes, unsigned int& pos)
        {}

public:

	Body(enum planeBodies name, unsigned int nshapes
					, float fualSize, float m, float coof
					, const Graphic::Shader& sh, const Graphic::Texture2D& tex
					, const glm::vec3& v3Pos = glm::vec3(0)
                    , const glm::vec3& v3Size = glm::vec3(1)
					, const glm::vec3& v3Speed = glm::vec3(0));
	
	virtual ~Body() {}

};
}

#endif
