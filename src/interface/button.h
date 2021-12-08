#ifndef BUTTOM_H
#define BUTTOM_H

#include <ft2build.h>
#include FT_FREETYPE_H
#include "../objects/graphic_object.h"
#include "../objects/collision.h"

namespace Interface {

class Button : public Graphic::GraphObject {

    glm::vec2 pV2Points[4];
    const char* title;
    bool pressed = false;

public:

    Button(glm::vec2 *pV2Two, const char* str
                            , Graphic::Shader& sh, Graphic::Texture2D& tex
                            , const glm::vec3& v3Pos = glm::vec3(0)
                            , const glm::vec3& v3Ratio = glm::vec3(1)
                            , const glm::vec3& v3Spd = glm::vec3(0)
                            , const glm::vec3& v3sl = { 0.0, 0.0, 1.0 }
                            , const float slAng = 0.0);

    void Press();

    virtual ~Button() {}


};
}

#endif
