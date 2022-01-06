#include "input.h"

Input::Input(float width, float height)
           : screenWidth(width), screenHeight(height) {}

void Input::MousePosition(float curX, float curY)
{
    
//    float delta_x = curPosX - curX;
	float delta_y = curPosY - curY;
    curPosX = curX;
    curPosY = curY;

    normX = curPosX/(screenWidth/2) - 1;
    normY = -(curPosY/(screenHeight/2) - 1);

//Для расчёта угла смещения мыши строится треуголник,
//в котором sensity и delta_y катиты, a через значение
//тангенса вычисляется угол.
	const float sensity = 500;
	angle = atan((delta_y/sensity));
    mouseInput = true;
}	

void Input::MouseButton(int button, int action, int modes)
{
    if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        mousePress = true;
    }
    if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) {
        mousePress = false;
    }
}

void Input::Scroll(float yOffset)
{ scroll = yOffset; }

//void Input::ChangeScroll(float newScroll)
//{ scroll = newScroll; }

void Input::Keyboard(int key, int scancode, int action, int modes)
{
    if(action == GLFW_PRESS) {
        pressedKeys[key] = true;
    } else if(action == GLFW_RELEASE) {
        pressedKeys[key] = false;
    }
    keyInput = true;
}

const bool* Input::Keys() const
{ return pressedKeys; }
float Input::GetScroll() const
{ return scroll; }
float Input::GetAngle() const
{ return angle; }
float Input::GetXPos() const
{ return curPosX; }
float Input::GetYPos() const
{ return curPosY; }
float Input::GetNormXPos() const
{ return normX; }
float Input::GetNormYPos() const
{ return normY; }
void Input::MouseNotPress()
{ mousePress = false; }
bool Input::MousePress() const
{ return mousePress; }
bool Input::MouseInput() const
{ return mouseInput; }
bool Input::KeyInput() const
{ return keyInput; } 
