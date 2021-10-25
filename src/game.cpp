#include "game.h"

void Game::Init(ILevel& level) const
{
	level.Load();
}

void Game::UpDate(float delta_time, ILevel& level) const
{
	camera.MoveCamera(delta_time);
	level.UpDate(delta_time, pressedKeys, angle);
}

void Game::KeyboardInput(GLFWwindow *pWindow, int key, int scancode,
												int action, int modes)
{
	switch(key) {
	case GLFW_KEY_ESCAPE:
		if(action == GLFW_PRESS) {
        	glfwSetWindowShouldClose(pWindow, GLFW_TRUE);
    	}
		break;
	case GLFW_KEY_W:
		if(action == GLFW_PRESS) {
			pressedKeys[W] = true;
		} 
		if(action == GLFW_RELEASE) {
			pressedKeys[W] = false;
		}
		break;
	case GLFW_KEY_S:
		if(action == GLFW_PRESS) {
			pressedKeys[S] = true;
		}
		if(action == GLFW_RELEASE) {
			pressedKeys[S] = false;
		}
		break;
	}
}	

void Game::MouseInput(float curY)
{
	float delta_y = lastPosY - curY;
	lastPosY = curY;

//Для расчёта угла смещения мыши строится треуголник,
//в котором sensity и delta_y катиты, a через значение
//тангенса вычисляется угол.
	const float sensity = 500;
	angle = atan((delta_y/sensity));
}	

