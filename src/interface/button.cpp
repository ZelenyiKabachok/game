#include "button.h"

GUI::Button::Button(const glm::vec2& v2First, const glm::vec2& v2Second
                            , const String& name
                            , Graphic::Shader& sh, Graphic::Texture2D& tex
                            , const glm::vec3& v3Pos
                            , const glm::vec3& v3Ratio
                            , const glm::vec3& v3Spd
                            , const glm::vec3& v3sl
                            , const float slAng)
                        : Graphic::GraphObject(sh, tex, v3Pos, v3Ratio
                                        , v3Spd, v3sl, slAng)
{
    sTitle = name;

    //Получение крайних точек.
    glm::vec4 v4Left = this->matPosition * this->matSize
                        * glm::vec4(-1.0, -1.0, 0.0, 1.0); 
    glm::vec4 v4Right = this->matPosition * this->matSize
                        * glm::vec4(1.0, 1.0, 0.0, 1.0);
    pV2Points[0].x = v4Left.x;
    pV2Points[0].y = v4Left.y;
    pV2Points[1].x = v4Right.x;
    pV2Points[1].y = v4Right.y;
} 

GUI::Button::Button(const Button& button)
                : Graphic::GraphObject(button)
{
    sTitle = button.sTitle;
    pV2Points[0] = button.pV2Points[0];
    pV2Points[1] = button.pV2Points[1];
}


void GUI::Button::Draw(const Camera& camera)
{
    switch(state) {
    case NOT_HOVERED:
        this->ChangeColor(glm::vec3(0.7f));
        break;
    case PRESSED:
        this->ChangeColor(glm::vec3(0.4f));
        break;
    default:
        this->ChangeColor(glm::vec3(1.0f));
    }
    shader.Use();

    glActiveTexture(GL_TEXTURE0);
    texture.Bind();

    shader.SetMatrix4("matCamera", glm::mat4(1.0f));
    shader.SetMatrix4("matPosition", matPosition);
    shader.SetMatrix4("matRotation", matRotation);
    shader.SetMatrix4("matScale", matSize);
    shader.SetVector3("v3Color", v3Color);
   
    glBindVertexArray(VAO);
    glDrawElements(type, points, GL_UNSIGNED_INT, 0);
}


const glm::vec2* GUI::Button::GetCoord()
{ return pV2Points; }

void GUI::Button::ChangeState(GUI::State newState, Setting& data)
{
    state = newState;
} 
