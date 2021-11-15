#ifndef TAIL_H
#define TAIL_H

#include "../physical_object.h"
#include "../shape.h"

enum planeTails { RUST_TAIL };

//Хвост для самолёта.
//Направляет самолёт.
class Tail : public PhysicObject {
	friend class Plane;

	const enum planeTails Name;
	const unsigned int num_shapes; //количество фигур самолёта для коллизии.

	float DirAngle; //Угол для расчёта вектора направления.
	vec3 direction; //Еденичный вектор направления.

	float PlaneAngle; //Угол наклона самолёта.

//Изменяет вектор направления самолёта.
//Управление мышью.
	void FindDirect(float alpha);

	virtual void GetShapes(Shape** const planeShapes, unsigned int& pos) {};

//Находит угол наклона cамолёта.
	void FindAngle(const vec3& PlaneSpeed);

public:

	Tail(enum planeTails name, unsigned int nshapes,
					float DirAlpha, float m, float coof, 
					const Shader& sh, const Texture2D& tex, 
					const vec3& pos = vec3(0), const vec3& size = vec3(1),
					const vec3& speed = vec3(0)); 

	virtual ~Tail() {}

};

#endif
