#ifndef GAME_H
#define GAME_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <cstdio>
#include <map>

#include "levels.h"
#include "loads.h"
#include "objects.h"
#include "camera.h"

extern Camera camera;

class Game {
public:	

	Game() {}

	~Game() {}

	void Init(ILevel& level);

	void UpDate(float delta_time, ILevel& level);

};

#endif
