#include "button.h"

GUI::Button::Button(const glm::vec2& v2First, const glm::vec2& v2Second
                            , const char* str, int length
                            , Graphic::Shader& sh, Graphic::Texture2D& tex
                            , const glm::vec3& v3Pos
                            , const glm::vec3& v3Ratio
                            , const glm::vec3& v3Spd
                            , const glm::vec3& v3sl
                            , const float slAng)
                        : Graphic::GraphObject(sh, tex, v3Pos, v3Ratio
                                        , v3Spd, v3sl, slAng), size(length)
{
    sTitle = new char[size];
    for(int i = 0; i < size; i++) {
        sTitle[i] = str[i];
    }
    pV2Points[0] = v2First;
    pV2Points[1] = v2Second;
} 

GUI::Button::Button(const Button& button)
                : Graphic::GraphObject(button)
{
    sTitle = new char[button.size];
    for(int i = 0; i < size; i++) {
        sTitle[i] = button.sTitle[i];
        }
    pV2Points[0] = button.pV2Points[0];
    pV2Points[1] = button.pV2Points[1];
}

GUI::Button::~Button()
{
    delete[] sTitle;
//    delete[] pV2Points;
}

const glm::vec2* GUI::Button::GetCoord()
{ return pV2Points; }

void GUI::Button::Press()
{
} 
