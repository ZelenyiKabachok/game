#include "load_button.h"

GUI::LoadButton::LoadButton(const Graphic::VisualString& string
                          , const glm::vec3& v3Pos
                          , int screenWidth, int screenHeight)
                    : Button(string
                        , ResourceManager::Instance().GetShader("graphic")
                        , ResourceManager::Instance().GetTexture("button")
                        , screenWidth, screenHeight
                        , v3Pos, glm::vec3(120, 35, 1))
{}

void GUI::LoadButton::ChangeState(GUI::State newState, Data& data
                                                     , const Input& input)
{
    this->state = newState;
    if(this->state == PRESSED) 
    { data.sData = this->title.GetString(); }
}
