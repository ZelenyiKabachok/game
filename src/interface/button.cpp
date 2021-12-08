#include "button.h"

Interface::Button::Button(glm::vec2 *pV2Two, const char* str
                            , Graphic::Shader& sh, Graphic::Texture2D& tex
                            , const glm::vec3& v3Pos
                            , const glm::vec3& v3Ratio
                            , const glm::vec3& v3Spd
                            , const glm::vec3& v3sl
                            , const float slAng)
                        : Graphic::GraphObject(sh, tex, v3Pos, v3Ratio
                                        , v3Spd, v3sl, slAng), title(str)
{
    pV2Points[0] = pV2Two[0];
    pV2Points[1] = glm::vec2(pV2Two[0].x, pV2Two[1].y);
    pV2Points[2] = pV2Two[1];
    pV2Points[3] = glm::vec2(pV2Two[1].x, pV2Two[0].y);
} 

void Interface::Button::Press()
{
} 
