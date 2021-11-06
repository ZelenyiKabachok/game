#ifndef GRAVITY_OBJECT_H
#define GRAVITY_OBJECT_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "graphic_object.h"

//Класс PhysicObject наследуется от класса GraphObject.
//Учитывает коллизию объекта и силы, действующие на него.
class PhysicObject : public GraphObject {

protected:
	float mass;
//Коэфициент для расчёта силы сопротивления воздуха.
//Зависит от полощади и обтекаемости объекта, но программист сам его задаёт.
	float coofResistance; 
	vec3 ForceOfAttract = vec3(0);

public:

	PhysicObject(float m, float coof, const Shader& sh, 
					const Texture2D& tex, const vec3& pos = vec3(0),
					const vec3& size = vec3(1), const vec3& speed = vec3(0));

	virtual ~PhysicObject() {}

	PhysicObject(float m, float coof, GraphObject object);

//Вычисляя равнодеёствующую всех сил, изменяет вектор скорости объекта.
//Вызывает метод void Move(const float, const vec3&, const float).
	void AttractAndMove(float delta_time, const vec3& Force = vec3(0),
						const vec3& RotationVec = vec3(1), float angle = 0);

};

#endif
