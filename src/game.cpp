#include "game.h"

void Game::Init(const FT_Face& face, ILevel& level, int width, int height)
{
    input = new Input(width, height);
	level.Load(face, width, height);
}

void Game::UpDate(float delta_time, ILevel& level)
{
	level.UpDate(delta_time, *input);
    input->Scroll(0.0);
    input->MouseNotPress();
	level.Render();
}

void Game::KeyboardInput(int key, int scancode, int action, int modes)
{
    input->Keyboard(key, scancode, action, modes);
}	

void Game::MousePosition(float curX, float curY)
{
    input->MousePosition(curX, curY);
//    Interface
}	

void Game::MouseButton(int button, int action, int modes)
{
    input->MouseButton(button, action, modes);
}

void Game::ScrollInput(float yOffset)
{
    input->Scroll(yOffset);
}

enum Levels whatLevel(const String& str)
{
    int quant = 2;
    String levels[quant] {
        String("Collisions_Editor")
      , String("First_Level")
    };
    for(int i = 0; i < quant; i++) {
        if(str == levels[i]) {
            return (Levels)(i);
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

Game::~Game()
{
    delete input;
}
