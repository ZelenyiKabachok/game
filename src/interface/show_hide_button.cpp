#include "show_hide_button.h"

GUI::ShowHideBut::ShowHideBut(const Graphic::GraphObject *pGrObj
                            , const glm::vec3& v3Pos
                            , int screenWidth, int screenHeight)
                 : Button(Graphic::VisualString(screenWidth, screenHeight
                            , " ", glm::vec3(0.0), glm::vec3(1.0))
                    , ResourceManager::Instance().GetShader("graphic")
                    , ResourceManager::Instance().GetTexture("coord")
                    , screenWidth, screenHeight, v3Pos
                    , glm::vec3(30, 30, 0))
                 , pObject(pGrObj)
{}

void GUI::ShowHideBut::Draw(const Camera& camera, const Character *pCharacters
                                         , unsigned int VBO, unsigned int VAO)
{
    if(show) { pObject->Draw(camera); }
    this->Button::Draw(camera, pCharacters, VBO, VAO);
}

void GUI::ShowHideBut::ChangeState(State newState, Data& data
                                        , const Input& input)
{
    this->state = newState;
    if(this->state == PRESSED) { show = !show; }
}
