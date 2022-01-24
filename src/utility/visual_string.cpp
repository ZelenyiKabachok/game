#include "visual_string.h"

Graphic::VisualString::VisualString(int screenWidth, int screenHeight
                                  , const String& name
                                  , const glm::vec3& v3Pos
                                  , const glm::vec3& v3Col, float size)
                        : string(name), v3Position(v3Pos)
                        , v3Color(v3Col), scale(size)
                        , shader(ResourceManager::Instance().GetShader("text"))
{
    glm::mat4 matProjection = glm::ortho(0.0, (double)(screenWidth)
                                       , 0.0, (double)(screenHeight));
    shader.Use();
    shader.SetMatrix4("matProjection", matProjection);
}

const String& Graphic::VisualString::GetString()
{ return string; }

void Graphic::VisualString::ChangeString(const String& newString)
{ string = newString; }

void Graphic::VisualString::Draw(const Character *pCharacters
                               , unsigned int VBO, unsigned VAO)
{
    shader.Use();
    glActiveTexture(GL_TEXTURE0);
    glBindVertexArray(VAO);

    shader.SetVector3("Color", v3Color);

    float textXPos = v3Position.x;
    float textYPos = v3Position.y;
 
    for (unsigned int i = 0; i < string.Size(); i++)
    {
        Character Char = pCharacters[(int)(string[i])];
 
        float xPos = textXPos + Char.v2Bearing.x * scale;
        float yPos = textYPos - (Char.v2Size.y - Char.v2Bearing.y) * scale;
 
        float width = Char.v2Size.x * scale;
        float height = Char.v2Size.y * scale;
 
        float vertices[6][4] = {
            { xPos, yPos + height, 0.0f, 0.0f },            
            { xPos, yPos, 0.0f, 1.0f },
            { xPos + width, yPos, 1.0f, 1.0f },
 
            { xPos, yPos + height, 0.0f, 0.0f },
            { xPos + width, yPos, 1.0f, 1.0f },
            { xPos + width, yPos + height, 1.0f, 0.0f }           
        };
 
        Char.texture.Bind();
 
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices); 
        glBindBuffer(GL_ARRAY_BUFFER, 0);
 
        glDrawArrays(GL_TRIANGLES, 0, 6);
 
        textXPos += (Char.advance >> 6) * scale;
    }
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Graphic::VisualString::ChangePosition(int screenHeight
                                         , const glm::vec3& v3NewPos)
{ v3Position = v3NewPos; }
