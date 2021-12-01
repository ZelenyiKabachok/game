#ifndef FIRST_LEVEL_H
#define FIRST_LEVEL_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "level.h"

class FirstLevel : public ILevel {

	Camera *pCamera;

	List<Graphic::GraphObject> GrObjects;

	List<Physic::PhysicObject> PhObjects;

	Physic::PCollisions CollObjects;	

	Aircraft::Plane *pPlane;
	
public:

	FirstLevel(); 

	virtual void Load();

	virtual void UpDate(float delta_time, const bool *pKeys, const float angle);

	virtual void Render();

	virtual ~FirstLevel();

};

#endif
