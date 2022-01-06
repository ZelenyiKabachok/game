#ifndef VISUAL_STRING_H
#define VISUAL_STRING_H

#include "resources.h"
#include "string.h"
#include "character.h"

namespace Graphic {

class VisualString/* : public ShapeDraw */{

    String string;
    glm::vec3 v3Position;
    glm::vec3 v3Color;
    float scale;

    Shader shader;

public:

    VisualString(int screenWidth, int screenHeight
               , const String& name, const glm::vec3& v3Pos
               , const glm::vec3& v3Col, float size = 1);

    void Draw(const Character *pCharacters
            , unsigned int VBO, unsigned int VAO);

    const String& GetString();

    void ChangeString(const String& newString);

    void ChangePosition(int screenHeight, const glm::vec3& v3NewPos);

    ~VisualString() {}

}; 
}

#endif
