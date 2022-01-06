#include "load_button.h"

GUI::LoadButton::LoadButton(const Graphic::VisualString& string
                          , const glm::vec3& v3Pos
                          , int screenWidth, int screenHeight)
                    : Button(string
                        , ResourceManager::Instance().GetShader("button")
                        , ResourceManager::Instance().GetTexture("button")
                        , screenWidth, screenHeight
                        , v3Pos, glm::vec3(120, 35, 1))
{}

void GUI::LoadButton::ChangeState(GUI::State newState, Setting& data)
{
    this->state = newState;
    if(this->state == PRESSED) 
    { data.string = this->title.GetString(); }
}
