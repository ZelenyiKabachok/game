#include "game.h"

void Game::Init(ILevel& level) const
{
	level.Load();
}

void Game::UpDate(float delta_time, ILevel& level)
{
    if(haveScroll) {
	    level.UpDate(delta_time, pressedKeys, angle, scroll);
        haveScroll = false;
    } else {
	    level.UpDate(delta_time, pressedKeys, angle, 0.0);
    }
	level.Render();
}

void Game::KeyboardInput(GLFWwindow *pWindow, int key, int scancode
											, int action, int modes)
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
	case GLFW_KEY_A:
		if(action == GLFW_PRESS) {
			pressedKeys[A] = true;
		} 
		if(action == GLFW_RELEASE) {
			pressedKeys[A] = false;
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
    case GLFW_KEY_D:
		if(action == GLFW_PRESS) {
			pressedKeys[D] = true;
		} 
		if(action == GLFW_RELEASE) {
			pressedKeys[D] = false;
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

void Game::ScrollInput(float yOffset)
{
    haveScroll = true;
    scroll = yOffset;
}

int getSize(const char* str)
{
    int i;
    for(i = 0; str[i] != '\0'; i++)
        {}
    return i+1;
}

bool compareStrings(const char* str1, const char* str2)
{
    int size1 = getSize(str1);
    int size2 = getSize(str2);
    if(size1 != size2) {
        return false;
    }
    for(int i = 0; i < size1; i++) {
        if(str1[i] != str2[i]) {
            return false;
        }
    }
    return true;
}

enum Levels whatLevel(const char* str)
{
    int quant = 2;
    const char *levels[quant] {
        {"Collisions_Editor"},
        {"First_Level"},
    };
    for(int j = 0; j < quant; j++) {
        if(compareStrings(str, levels[j])) {
            return (Levels)(j);
        }        
    }
    return NOTHING;
}

ILevel* Game::ChooseLevel(GLFWwindow *pWindow, int argc, char **argv)
{
    if(argc <= 1) {
	    glfwSetInputMode(pWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        return new FirstLevel;
    }
    switch(whatLevel(argv[1])) {
    case COLLISIONS_EDITOR:
        return new CollisionsEditor;
    default:
	    glfwSetInputMode(pWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        return new FirstLevel;
    }
}


