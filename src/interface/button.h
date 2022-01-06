#ifndef BUTTOM_H
#define BUTTOM_H

#include <ft2build.h>
#include FT_FREETYPE_H
#include "../objects/collision.h"
#include "../utility/resources.h"
#include "../utility/visual_string.h"
#include "setting.h"

namespace GUI {

enum State { PRESSED, HOVERED, NOT_HOVERED };

class Button : public Graphic::GraphObject {
protected:

    glm::vec2 pV2Points[2];

    Graphic::VisualString title;

    enum State state = NOT_HOVERED;

public:

    Button(const Graphic::VisualString& string
         , Graphic::Shader& sh, Graphic::Texture2D& tex
         , int screenWidth, int screenHeight
         , const glm::vec3& v3Pos = glm::vec3(0)
         , const glm::vec3& v3Ratio = glm::vec3(1)
         , const glm::vec3& v3Spd = glm::vec3(0)
         , const glm::vec3& v3sl = { 0.0, 0.0, 1.0 }
         , const float slAng = 0.0);

    Button(const Button& button);

    virtual void InitShaderData();

    virtual void ChangeState(State newState, Setting& data);

    virtual void Draw(const Character *pCharacters
                    , unsigned int VBO, unsigned int VAO);

    void AlignText(int screenHeight);

    const glm::vec2* GetCoord();

    virtual ~Button() {}

};
}

#endif
