#include "game.h"

void Game::Init(ILevel& level) const
{
	level.Load();
}

void Game::UpDate(float delta_time, ILevel& level)
{
	level.UpDate(delta_time, input.Keys(), input.GetAngle(), input.GetScroll());
    input.ChangeScroll(0.0);
	level.Render();
}

void Game::KeyboardInput(int key, int scancode, int action, int modes)
{
    input.Keyboard(key, scancode, action, modes);
}	

void Game::MouseInput(float curX, float curY)
{
    input.Mouse(curX, curY);
}	

void Game::ScrollInput(float yOffset)
{
    input.Scroll(yOffset);
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


