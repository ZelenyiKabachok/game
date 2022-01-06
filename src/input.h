#ifndef INPUT_H
#define INPUT_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cmath>

class Input {

	bool pressedKeys[128] = { false };  //Нажатые клавишы
    float scroll = 0;    

    bool mouseInput = false;
    bool keyInput = false;
    bool mousePress = false; 
    

    float screenWidth;
    float screenHeight;

    float curPosX = 0;      
    float curPosY = 0;

    float normX;                //Координаты курсора в системе
                                //координат от (-1; -1) до (1; 1).
    float normY;

	float angle = 0;	        //Угол смещение мыши для Aircraft::Plane::Fly

public:
    
    Input(float width, float height);

    void Keyboard(int key, int scancode, int action, int modes);

	void MousePosition(float curX, float curY);

    void MouseButton(int button, int action, int modes);

    void Scroll(float yOffset);
    //void ChangeScroll(float newScroll); 

    const bool* Keys() const;
    float GetScroll() const;
    float GetAngle() const;
    float GetXPos() const;
    float GetYPos() const;
    float GetNormXPos() const;
    float GetNormYPos() const;
    void MouseNotPress();
    bool MousePress() const;
    bool MouseInput() const;
    bool KeyInput() const;

    ~Input() {}
};

#endif
