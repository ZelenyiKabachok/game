#ifndef BODY_H
#define BODY_H

#include "../physical_object.h"
#include "../shape.h"

enum planeBodies { RUST_BODY };

//Корпус для самолёта.
//Содержит информация о количестве топлива.
class Body : public PhysicObject {
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
	vec3 StartEnginesPos[1];
	vec3 StartWingsPos[1];
	vec3 StartTailsPos[1];

private:
//Сжегает топливо.
	void BurnFuel(float fuelConsumption);

	virtual void GetShapes(Shape** planeShapes, unsigned int& pos) {}

public:

	Body(enum planeBodies name, unsigned int nshapes,
					float fualSize, float m, float coof, 
					const Shader& sh, const Texture2D& tex, 
					const vec3& pos = vec3(0), const vec3& size = vec3(1),
					const vec3& speed = vec3(0));
	
	virtual ~Body() {}

};

#endif
