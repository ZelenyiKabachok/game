#include "load_button.h"

GUI::LoadButton::LoadButton(Graphic::Shader& shader, Graphic::Texture2D texture
                                                 , const char *str, int length)
                : Button(glm::vec2(-1.0, -0.5), glm::vec2(1.0, 0.5)
                        , str, length, shader, texture)
{}

void GUI::LoadButton::Press()
{
//    sActive = this->sTitle;
}
