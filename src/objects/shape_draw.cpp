#include "shape_draw.h"

Graphic::ShapeDraw::ShapeDraw(Shader& sh, Texture2D& tex
					 , const glm::vec3& v3Pos
                     , const glm::vec3& v3Size
                     , const glm::vec3& v3Speed
					 , const glm::vec3& v3Slant
                     , const float slAng)
				: GraphObject(sh, tex, v3Pos, v3Size, v3Speed, v3Slant, slAng)
{}

void Graphic::ShapeDraw::initShaderData(const float *pData
                                      , const glm::vec3& v3Col
								      , unsigned int vertexes
                                      , GLenum DrawType)
{
	this->type = DrawType;
	this->points = vertexes;
	this->v3Color = v3Col;
	unsigned int VBO;
    glGenVertexArrays(1, &(this->VAO));
    glGenBuffers(1, &VBO);
	
    glBindVertexArray(this->VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, 3*vertexes * sizeof(float)
                                    , pData, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);
    glEnableVertexAttribArray(0);
}

void Graphic::ShapeDraw::initShaderData(const glm::vec2 *pData
                                      , const glm::vec3& v3Col
								      , unsigned int vertexes
                                      , GLenum DrawType)
{
	float pArrData[vertexes*3] = {0.0};
	for(unsigned int i = 0, j = 0; i < vertexes; i++, j += 3) {
		pArrData[j] = pData[i].x;
		pArrData[j+1] = pData[i].y;
	}
	initShaderData(pArrData, v3Col, vertexes, DrawType);
}

void Graphic::ShapeDraw::Draw(const Camera& camera, float width) const
{
	shader.Use();
	glActiveTexture(GL_TEXTURE0);
	texture.Bind();

	shader.SetVector3("v3Color", this->v3Color);
	shader.SetMatrix4("matCamera", camera.GetMatrix());
	shader.SetMatrix4("matPosition", this->matPosition);
	shader.SetMatrix4("matRotate", this->matRotation);
	shader.SetMatrix4("matScale", this->matSize);
	glBindVertexArray(this->VAO);

	glLineWidth(width);
	glPointSize(width);
	glDrawArrays(this->type, 0, this->points);
}

void Graphic::ShapeDraw::Move(const char *sUniPos, const glm::vec3& v3Pos)
{
	shader.SetVector3(sUniPos, v3Pos);
}
