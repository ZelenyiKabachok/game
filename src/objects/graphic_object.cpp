#include "graphic_object.h"

void GraphObject::initShaderData(const float *Data, const unsigned int *indices,
								 int DataVert, int IndicesQuantity)
{
	unsigned int VBO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
	
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, DataVert * sizeof(float), Data, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, IndicesQuantity * sizeof(float),
													indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), NULL);
    glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float),
												(void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

}

void GraphObject::Draw(const Camera& camera) const
{
	shader.Use();

	glActiveTexture(GL_TEXTURE0);
	texture.Bind();

	glm::mat4 ModelMatrix = PositionMatrix * RotateMatrix * SizeMatrix;

	shader.SetMatrix4("CameraMatrix", camera.GetCameraMatrix());
	shader.SetMatrix4("ModelMatrix", ModelMatrix);
	
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void GraphObject::Move(const float delta_time)
{
	ObPosition += ObSpeed * delta_time;
	PositionMatrix = glm::translate(glm::mat4(1.0f), ObPosition);
}

void GraphObject::Rotate(const vec3& rotateVector, const float angle)
{
	RotateMatrix = glm::rotate(mat4(1.0f), SlantAngle, SlantVector);
	RotateMatrix *= glm::rotate(mat4(1.0f), angle, rotateVector);
}

void GraphObject::Scale()
{
	SizeMatrix = glm::scale(mat4(1.0f), ObSize);
}

GraphObject::GraphObject(const Shader& sh, const Texture2D& tex, 
						 const vec3& pos, const vec3& size, const vec3& speed,
						 const vec3& slVec, const float slAng)
		: shader(sh), texture(tex), ObPosition(pos)
		, ObSize(size), ObSpeed(speed), SlantVector(slVec), SlantAngle(slAng)
{
	Move(0.0);
	Rotate();
	Scale();
}

void GraphObject::ChangeTexture(const Texture2D& tex)
{ texture = tex; }

void GraphObject::ChangeSlantVector(const vec3& newSlVec)
{ SlantVector = newSlVec; Rotate(); }

void GraphObject::ChangeSlantAngle(float angle)
{ SlantAngle = angle; Rotate(); }

void GraphObject::ChangeSize(const vec3& newSize)
{ ObSize = newSize; Scale(); }

void GraphObject::ChangeSpeed(const vec3& newSpeed)
{ ObSpeed = newSpeed; }

void GraphObject::ChangePosition(const vec3& newPos)
{ ObPosition = newPos; Move(0.0); }

vec3 GraphObject::GetSpeed() const { return ObSpeed; }
vec3 GraphObject::GetPosition() const { return ObPosition; }
