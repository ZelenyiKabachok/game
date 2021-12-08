#ifndef INPUT_H
#define INPUT_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cmath>

class Input {

	bool pressedKeys[128];  //Нажатые клавишы
    float scroll = 0;    

    bool mouseInput = false;
    bool keyInput = false;

    float curPosX = 0;
    float curPosY = 0;

	float angle = 0;	        //Угол смещение мыши для Aircraft::Plane::Fly

public:
    
    Input() {}

    void Keyboard(int key, int scancode, int action, int modes);

	void Mouse(float curX, float curY);

    void Scroll(float yOffset);

    const bool* Keys();
    void ChangeScroll(float newScroll); 
    float GetScroll();
    float GetAngle();
    bool MouseInput();
    bool KeyInput();

    ~Input() {}
};

#endif
