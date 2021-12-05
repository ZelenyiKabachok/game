#ifndef GAME_H
#define GAME_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <cstdio>
#include <map>

#include "levels.h"
#include "utility/resources.h"
#include "objects.h"
#include "camera.h"

enum Levels { COLLISIONS_EDITOR, FIRST_LEVEL, NOTHING };

extern const int Width;
extern const int Height;

class Game {

	bool pressedKeys[4];    //Нажатые клавишы
    float scroll;
    bool haveScroll;

	float lastPosY; 	    //Предыдущая Y-позиция мыши.
	float angle;	        //Угол смещение мыши.

public:	

	Game() : lastPosY(Height/2), angle(0) {}

	~Game() {}

	void KeyboardInput(GLFWwindow *pWindow, int key, int scancode
										  , int action, int modes);

	void MouseInput(float curY);

    void ScrollInput(float yOffset);

	void Init(ILevel& level) const;

	void UpDate(float delta_time, ILevel& level);

    ILevel* ChooseLevel(GLFWwindow *pWindow, int argc, char **argv);

};

#endif
