#ifndef FIRST_LEVEL_H
#define FIRST_LEVEL_H

#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "level.h"

using glm::vec3;

extern ResourceManager resources;

class FirstLevel : public ILevel {

	Camera camera;

	std::vector<GraphObject> GrObjects;

	std::vector<PhysicObject> PhObjects;

	Plane *plane;
	

public:

	FirstLevel(); 

	virtual void Load();

	virtual void UpDate(float delta_time, const bool *keys, const float angle);

	virtual void Render();

	virtual ~FirstLevel();

};

#endif
