#include "graphic_object.h"

void Graphic::GraphObject::InitShaderData(const float *pData
                                , const unsigned int *pIndices
								, int numOfVert, unsigned int numOfInd
								, GLenum DrawType)
{
	type = DrawType;
	points = numOfInd;
	GLuint VBO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
	
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, numOfVert * sizeof(float), pData
                                                  , GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, numOfInd * sizeof(float),
													pIndices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), NULL);
    glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float),
												(void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

}

void Graphic::GraphObject::Draw(const Camera& camera) const
{
	shader.Use();

	glActiveTexture(GL_TEXTURE0);
	texture.Bind();

	shader.SetMatrix4("matCamera", camera.GetMatrix());
	shader.SetMatrix4("matPosition", matPosition);
    shader.SetMatrix4("matRotation", matRotation);
    shader.SetMatrix4("matScale", matSize);
	shader.SetVector3("v3Color", v3Color);
	
	glBindVertexArray(VAO);
	glDrawElements(type, points, GL_UNSIGNED_INT, 0);
}

void Graphic::GraphObject::Move(const float delta_time)
{
	v3Position += v3Speed * delta_time;
	matPosition = glm::translate(glm::mat4(1.0f), v3Position);
}

void Graphic::GraphObject::Rotate(const glm::vec3& v3Rotate, const float angle)
{
	matRotation = glm::rotate(glm::mat4(1.0f), SlantAngle, v3Slant);
	matRotation *= glm::rotate(glm::mat4(1.0f), angle, v3Rotate);
}

void Graphic::GraphObject::Scale()
{
	matSize = glm::scale(glm::mat4(1.0f), v3Size);
}

Graphic::GraphObject::GraphObject(Graphic::Shader& sh
                                , Graphic::Texture2D& tex
						        , const glm::vec3& v3Pos
                                , const glm::vec3& v3Ratio
                                , const glm::vec3& v3Spd
						        , const glm::vec3& v3Sl
                                , const float slAng)
		: shader(sh), texture(tex), v3Position(v3Pos)
		, v3Size(v3Ratio), v3Speed(v3Spd), v3Slant(v3Sl), SlantAngle(slAng)
{
	Move(0.0);
	Rotate();
	Scale();
}

void Graphic::GraphObject::ChangeTexture(const Graphic::Texture2D& tex)
{ texture = tex; }

void Graphic::GraphObject::ChangeColor(const glm::vec3& v3NewColor)
{ v3Color = v3NewColor; }

void Graphic::GraphObject::ChangeSlantVector(const glm::vec3& v3NewSlant)
{ v3Slant = v3NewSlant; Rotate(); }

void Graphic::GraphObject::ChangeSlantAngle(float angle)
{ SlantAngle = angle; Rotate(); }

void Graphic::GraphObject::ChangeSize(float newSize)
{ v3Size *= newSize; Scale(); }

void Graphic::GraphObject::ChangeSpeed(const glm::vec3& v3NewSpeed)
{ v3Speed = v3NewSpeed; }

void Graphic::GraphObject::ChangePosition(const glm::vec3& v3NewPos)
{ v3Position = v3NewPos; Move(0.0); }

glm::vec3 Graphic::GraphObject::GetSpeed() const
{ return v3Speed; }
glm::vec3 Graphic::GraphObject::GetPosition() const
{ return v3Position; }
const Graphic::Shader& Graphic::GraphObject::GetShader() const
{ return shader; }
const Graphic::Texture2D& Graphic::GraphObject::GetTexture() const
{ return texture; }
