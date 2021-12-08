#include "input.h"

void Input::Mouse(float curX, float curY)
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

void Input::Scroll(float yOffset)
{
    scroll = yOffset;
}


void Input::Keyboard(int key, int scancode, int action, int modes)
{
    if(action == GLFW_PRESS) {
        pressedKeys[key] = true;
    } else {
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
