#ifndef GRAVITY_OBJECT_H
#define GRAVITY_OBJECT_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "graphic_object.h"

namespace Physic {

//Класс PhysicObject наследуется от класса GraphObject.
//Учитывает коллизию объекта и силы, действующие на него.
class PhysicObject : public Graphic::GraphObject {

protected:
	float mass;
//Коэфициент для расчёта силы сопротивления воздуха.
//Зависит от полощади и обтекаемости объекта, но программист сам его задаёт.
	float coofResistance; 
	glm::vec3 v3ForceOfAttract = glm::vec3(0);

public:

	PhysicObject(float m, float coof, const Graphic::Shader& sh
					, const Graphic::Texture2D& tex
                    , const glm::vec3& v3Pos = glm::vec3(0)
                    , const glm::vec3& v3Size = glm::vec3(1)
                    , const glm::vec3& v3Speed = glm::vec3(0)
					, const glm::vec3& v3Slant = { 0.0, 0.0, 1.0 }
                    , const float angle = 0);

	virtual ~PhysicObject() {}

	PhysicObject(float m, float coof, Graphic::GraphObject object);

//Вычисляя равнодеёствующую всех сил, изменяет вектор скорости объекта.
//Вызывает метод void Move(const float, const vec3&, const float).
	void AttractAndMove(float delta_time
                    , const glm::vec3& v3Force = glm::vec3(0));

};
}

#endif
