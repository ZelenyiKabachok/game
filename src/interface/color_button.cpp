#include "color_button.h"

GUI::ColorButton::ColorButton(const glm::vec3& v3Pos
                            , int screenWidth, int screenHeight)
                 : Button(Graphic::VisualString(screenWidth, screenHeight
                            , " ", glm::vec3(0.0), glm::vec3(1.0))
                    , ResourceManager::Instance().GetShader("graphic")
                    , ResourceManager::Instance().GetTexture("color")
                    , screenWidth, screenHeight, v3Pos
                    , glm::vec3(30, 30, 0))
{
    this->data.v3Data = glm::vec3(0.2);
}

void GUI::ColorButton::InitShaderData()
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
}

void GUI::ColorButton::ChangeState(GUI::State newState, Data& otherData
                                             , const Input& input)
{
    state = newState;
    if(state == PRESSED) {
        this->data.v3Data += 1.0;
    }
    glm::vec3 v3Color = this->data.v3Data;
    v3Color.x = ((int)(v3Color.x) % 10)/10.0;
    v3Color.y = v3Color.x;
    v3Color.z = v3Color.x;

    glClearColor(v3Color.x, v3Color.y, v3Color.z, 1.0);
}

