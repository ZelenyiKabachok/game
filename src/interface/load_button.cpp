#include "load_button.h"

GUI::LoadButton::LoadButton(const String& name, glm::vec3 v3Pos)
                    : Button(glm::vec2(-1.0, -0.5), glm::vec2(1.0, 0.5)
                        , name
                        , ResourceManager::Instance().GetShader("button")
                        , ResourceManager::Instance().GetTexture("button")
                        , v3Pos, glm::vec3(0.12, 0.06, 1))
{}

void GUI::LoadButton::ChangeState(GUI::State newState, Setting& data)
{
    this->state = newState;
    if(this->state == PRESSED) 
    { data.string = this->sTitle; }
}
