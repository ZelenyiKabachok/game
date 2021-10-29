#ifndef TAIL_H
#define TAIL_H

#include "../physical_object.h"

enum planeTail { RustTail };

//Хвост для самолёта.
//Направляет самолёт.
class Tail : public PhysicObject {
	friend class Plane;

	const enum planeTail Name;
	float angle; //Угол наклона.
	vec3 direction; //Еденичный вектор направления.

//Изменяет вектор направления самолёта.
//Управление мышью.
	void FindDirect(float alpha);

public:

	Tail(enum planeTail name, float alpha, float m, float coof, 
					const Shader& sh, const Texture2D& tex, 
					const vec3& pos = vec3(0), const vec3& size = vec3(1),
					const vec3& speed = vec3(0)); 

};

#endif
