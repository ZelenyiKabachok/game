#include "coordinate_system.h"

Graphic::CoordSystem::CoordSystem()
                    : GraphObject(
                        ResourceManager::Instance().GetShader("coord")
                      , ResourceManager::Instance().GetTexture("button"))
{}

void Graphic::CoordSystem::Init()
{

    float pPos[] = {
        -1000.0,  0.0, 0.0,
         1000.0,  0.0, 0.0,
         0.0,    -1000.0, 0.0,
         0.0,     1000.0, 0.0
    };
    float pCol[] = {
         1.0, 0.0, 0.0,
         1.0, 0.0, 0.0,
         0.0, 1.0, 0.0,
         0.0, 1.0, 0.0 
    };

    GLuint posVBO;
    GLuint colVBO;
    glGenBuffers(1, &posVBO);
    glGenBuffers(1, &colVBO);
    
    glBindBuffer(GL_ARRAY_BUFFER, posVBO);
    glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float)
                     , pPos, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, colVBO);
    glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float)
                     , pCol, GL_STATIC_DRAW);

    glGenVertexArrays(1, &(this->VAO));
    glBindVertexArray(this->VAO);

    glEnableVertexAttribArray(0); 
    glEnableVertexAttribArray(1); 

    glBindBuffer(GL_ARRAY_BUFFER, posVBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    glBindBuffer(GL_ARRAY_BUFFER, colVBO);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);

}

void Graphic::CoordSystem::Draw(const Camera& camera) const
{
    shader.Use();

    shader.SetMatrix4("matCamera", camera.GetMatrix());

    glLineWidth(1.5);
    glBindVertexArray(this->VAO);
    glDrawArrays(GL_LINES, 0, 4);
}
