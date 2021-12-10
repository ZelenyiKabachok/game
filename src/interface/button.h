#ifndef BUTTOM_H
#define BUTTOM_H

#include <ft2build.h>
#include FT_FREETYPE_H
#include "../objects/graphic_object.h"
#include "../objects/collision.h"

namespace GUI {

class Button : public Graphic::GraphObject {
protected:

    glm::vec2 pV2Points[2];

    char* sTitle;
    int size;

    bool pressed = false;

public:

    Button(const glm::vec2& v2First, const glm::vec2& v2Second
                            , const char* str, int length
                            , Graphic::Shader& sh, Graphic::Texture2D& tex
                            , const glm::vec3& v3Pos = glm::vec3(0)
                            , const glm::vec3& v3Ratio = glm::vec3(1)
                            , const glm::vec3& v3Spd = glm::vec3(0)
                            , const glm::vec3& v3sl = { 0.0, 0.0, 1.0 }
                            , const float slAng = 0.0);

    Button(const Button& button);

    virtual void Press();

    const glm::vec2* GetCoord();

    virtual ~Button();

};
}

#endif
