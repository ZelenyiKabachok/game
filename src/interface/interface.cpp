#include "interface.h"

GUI::Interface::Interface(const GUI::Button *buttons
                                  , int numOfBut)
                                  : quantity(numOfBut)
{
    ppButtons = new GUI::Button*[quantity];
    for(int i = 0; i < quantity; i++) {
        ppButtons[i] = new GUI::Button(buttons[i]);
    }
    
}

bool GUI::Interface::CheckMouse(const glm::vec2 *pV2Button
                              , const glm::vec2 v2Mouse)
{
    if(v2Mouse.x < pV2Button[0].x || v2Mouse.x > pV2Button[1].x)
    { return false; }
    if(v2Mouse.y < pV2Button[0].y || v2Mouse.y > pV2Button[1].y)
    { return false; }
    return true;
}

void GUI::Interface::Render(const Camera& camera)
{
    for(int i = 0; i < quantity; i++) {
        ppButtons[i]->Draw(camera);
    }
}

void GUI::Interface::MouseInput(float posX, float posY, bool press)
{
    glm::vec2 pos(posX, posY);
    for(int i = 0; i < quantity; i++) {
        if(CheckMouse(ppButtons[i]->GetCoord(), pos)) {
            if(press) {
                ppButtons[i]->Press();
                break;
            }
        }
    } 
}

GUI::Interface::~Interface()
{
    for(int i = 0; i < quantity; i++) {
        delete ppButtons[i];
    }
    delete[] ppButtons;
}
