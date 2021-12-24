#include "interface.h"

void GUI::Interface::Init(const GUI::Button *pButtons, int numOfBut)
{
   float vertexes[] = {
      -1.0, -1.0, 0.0,     0.0, 0.0,
      -1.0,  1.0, 0.0,     0.0, 1.0,
       1.0,  1.0, 0.0,     1.0, 1.0,
       1.0, -1.0, 0.0,     1.0, 0,0
    };
    unsigned int indices[] {
        0, 1, 2,
        0, 2, 3
    };

    quantity = numOfBut;
    ppButtons = new GUI::Button*[quantity];
    for(int i = 0; i < quantity; i++) {
        ppButtons[i] = new GUI::Button(pButtons[i]);
        ppButtons[i]->initShaderData(vertexes, indices, 20, 6);
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

void GUI::Interface::ChangeButtonState(GUI::Button* pButton
                                    , Setting& date, GUI::State state)
{
    pButton->ChangeState(state, date);
}

void GUI::Interface::Click(const Input& input, Setting& date)
{
    glm::vec2 pos(input.GetXPos(), input.GetYPos());
    for(int i = 0; i < quantity; i++) {
        if(CheckMouse(ppButtons[i]->GetCoord(), pos)) {
            if(input.MousePress()) {
                ChangeButtonState(ppButtons[i], date, GUI::PRESSED);
                continue;
            } else {
                ChangeButtonState(ppButtons[i], date, GUI::HOVERED);
                continue;
            }
        } else {
            ChangeButtonState(ppButtons[i], date, GUI::NOT_HOVERED);
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
