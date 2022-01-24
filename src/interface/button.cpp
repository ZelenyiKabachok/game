#include "button.h"

GUI::Button::Button(const Graphic::VisualString& string
                  , Graphic::Shader& sh, Graphic::Texture2D& tex
                  , int screenWidth, int screenHeight
                  , const glm::vec3& v3Pos, const glm::vec3& v3Ratio
                  , const glm::vec3& v3Spd, const glm::vec3& v3sl
                  , const float slAng)
                : Graphic::GraphObject(sh, tex, v3Pos, v3Ratio
                                          , v3Spd, v3sl, slAng)
                , title(string), v3DefColor(1.0f)
{
    //Получение крайних точек.
    glm::vec4 v4Left = this->matPosition * this->matSize
                        * glm::vec4(-1.0, -1.0, 0.0, 1.0); 
    glm::vec4 v4Right = this->matPosition * this->matSize
                        * glm::vec4(1.0, 1.0, 0.0, 1.0);

    pV2Points[0].x = v4Left.x;
    pV2Points[0].y = v4Left.y;
    pV2Points[1].x = v4Right.x;
    pV2Points[1].y = v4Right.y;

    matProjection = glm::ortho(0.0, (double)(screenWidth)
                             , 0.0, (double)(screenHeight));

    this->ChangeColor(v3DefColor);
} 

void GUI::Button::AlignText(int screenHeight)
{
    glm::vec2 v2Left = pV2Points[0];
    glm::vec2 v2Right = pV2Points[1];

    glm::vec3 v3VisStrPos(0.0);
    v3VisStrPos.x = v2Left.x + 0.09 * (v2Right.x - v2Left.x);
    v3VisStrPos.y = v2Left.y + 0.25 * (v2Right.y - v2Left.y);
    title.ChangePosition(screenHeight, v3VisStrPos);
}
 
GUI::Button::Button(const Button& button)
                  : Graphic::GraphObject(button)
                  , title(button.title)
{
    //pTitle = button.pTitle;
    pV2Points[0] = button.pV2Points[0];
    pV2Points[1] = button.pV2Points[1];
}

void GUI::Button::InitShaderData()
{
    float pVertexes[] = {   
      -1.0, -1.0, 0.0,     0.0, 0.0,
      -1.0,  1.0, 0.0,     0.0, 1.0,
       1.0,  1.0, 0.0,     1.0, 1.0,
       1.0, -1.0, 0.0,     1.0, 0,0 
    };  
    unsigned int pIndices[] {
        0, 1, 2,
        0, 2, 3
    };  

    this->GraphObject::InitShaderData(pVertexes, pIndices, 20, 6);

/*
    GLuint VBO, EBO;

    glGenVertexArrays(1, &(this->VAO));
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(this->VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), pVertexes
                                                            , GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), pIndices
                                                             , GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
*/
}

void GUI::Button::Draw(const Camera& camera, const Character* pCharacters
                                    , unsigned int VBO, unsigned int VAO)
{
    switch(state) {
    case HOVERED:
        this->ChangeColor(glm::vec3(v3DefColor+0.2f));
        break;
    case PRESSED:
        this->ChangeColor(glm::vec3(v3DefColor-0.1f));
        break;
    default:
        this->ChangeColor(glm::vec3(v3DefColor));
        break;
    }
    shader.Use();

    glActiveTexture(GL_TEXTURE0);
    texture.Bind();

    shader.SetMatrix4("matCamera", matProjection);
    shader.SetMatrix4("matPosition", matPosition);
    shader.SetMatrix4("matRotation", matRotation);
    shader.SetMatrix4("matScale", matSize);
    shader.SetVector3("v3Color", v3Color);
   
    glBindVertexArray(this->VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    title.Draw(pCharacters, VBO, VAO);
}

const glm::vec2* GUI::Button::GetCoord()
{ return pV2Points; }

const Data& GUI::Button::GetData()
{ return data; }

void GUI::Button::ChangeState(GUI::State newState, Data& data
                                            , const Input& input)
{
    state = newState;
} 
