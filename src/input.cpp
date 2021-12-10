#include "input.h"

void Input::MousePosition(float curX, float curY)
{
    
    float delta_x = curPosX - curX;
	float delta_y = curPosY - curY;
    curPosX = curX;
    curPosY = curY;

//Для расчёта угла смещения мыши строится треуголник,
//в котором sensity и delta_y катиты, a через значение
//тангенса вычисляется угол.
	const float sensity = 500;
	angle = atan((delta_y/sensity));
    mouseInput = true;
}	

void Input::MouseButton(int button, int action, int modes)
{
    if(button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
        press = true;
    }
    if(button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE) {
        press = false;
    }
}

void Input::Scroll(float yOffset)
{
    scroll = yOffset;
}


void Input::Keyboard(int key, int scancode, int action, int modes)
{
    if(action == GLFW_PRESS) {
        pressedKeys[key] = true;
    } else if(action == GLFW_RELEASE) {
        pressedKeys[key] = false;
    }
    keyInput = true;
}

const bool* Input::Keys()
{ return pressedKeys; }
void Input::ChangeScroll(float newScroll)
{ scroll = newScroll; }
float Input::GetScroll()
{ return scroll; }
float Input::GetAngle()
{ return angle; }
bool Input::MouseInput()
{ return mouseInput; }
bool Input::KeyInput()
{ return keyInput; }
