#ifndef INTERFACE_H
#define INTERFACE_H

#include "button.h"

namespace GUI {

class Interface {

    Button **ppButtons;
    int quantity;

private:

    bool CheckMouse(const glm::vec2 *pV2Button, const glm::vec2 v2Mouse);

public:

    Interface(const Button *buttons, int numOfBut);

    virtual void Render(const Camera& camera);

    virtual void MouseInput(float posX, float posY, bool press);

    static void RenderText();

    virtual ~Interface();

};
}

#endif
