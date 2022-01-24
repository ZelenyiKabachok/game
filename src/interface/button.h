#ifndef BUTTON_H
#define BUTTON_H

#include <ft2build.h>
#include FT_FREETYPE_H
#include "../input.h"
#include "../objects/collision.h"
#include "../utility/resources.h"
#include "../utility/visual_string.h"
#include "data.h"

namespace GUI {

enum State { PRESSED, HOVERED, NOT_HOVERED };

class Button : public Graphic::GraphObject {
protected:

    glm::vec2 pV2Points[2];
    glm::mat4 matProjection;

    Graphic::VisualString title;
    glm::vec3 v3DefColor;
    Data data;

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

    virtual void ChangeState(State newState, Data& data, const Input& input);

    virtual void Draw(const Camera& camera, const Character *pCharacters
                                   , unsigned int VBO, unsigned int VAO);

    void AlignText(int screenHeight);

    const Data& GetData(); 

    const glm::vec2* GetCoord();

    virtual ~Button() {}

};
}

#endif
