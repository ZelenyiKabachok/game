#ifndef INTERFACE_H
#define INTERFACE_H

#include "button.h"
#include "../input.h"

namespace GUI {

class Interface {
protected:

    Button **ppButtons = NULL;
    int quantity = 0;
    Character pCharacters[256];

    int screenWidth;
    int screenHeight; 

    unsigned int VBO;
    unsigned int VAO;

protected:

    bool CheckMouse(const glm::vec2 *pV2Button, const glm::vec2 v2Mouse);

    virtual void ChangeButtonState(Button* pButton, Setting& date, State state);

public:

    Interface(const FT_Face& face, int width, int height);

    virtual void Init(const Button *pButtons, int numOfBut);

    virtual void Render(const Camera& camera);

    virtual void Click(const Input& input, Setting& date);

    virtual ~Interface();

};
}

#endif
