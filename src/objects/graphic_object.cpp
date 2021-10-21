#include "graphic_object.h"

extern Camera camera;

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

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

}

void GraphObject::Move(const float delta_time, const vec3& rotateVector,
												const float angle)
{
	ObPosition += ObSpeed * delta_time;

	glm::mat4 Rotate = glm::rotate(mat4(1.0f), angle, rotateVector);
	glm::mat4 Position = glm::translate(glm::mat4(1.0f), ObPosition);
	glm::mat4 Size = glm::scale(mat4(1.0f), ObSize);

	glm::mat4 Model = Position * Rotate * Size;
	Draw(Model);
}

void GraphObject::Draw(const mat4& Model)
{
	shader.Use();

	glActiveTexture(GL_TEXTURE0);
	texture.Bind();

	shader.SetMatrix4("CameraMatrix", camera.GetCameraMatrix());
	shader.SetMatrix4("ModelMatrix", Model);
	
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

GraphObject::GraphObject(const Shader& sh, const Texture2D& tex, 
						const vec3& pos, const vec3& size, const vec3& speed) : 
	shader(sh), texture(tex), ObPosition(pos), ObSize(size), ObSpeed(speed)
{}

void GraphObject::ChangeTexture(const Texture2D& tex)
{ texture = tex; }

void GraphObject::ChangeSize(const vec3& newSize)
{ ObSize = newSize; }

void GraphObject::ChangeSpeed(const vec3& newSpeed)
{ ObSpeed = newSpeed; }

void GraphObject::ChangePosition(const vec3& newPos)
{ ObPosition = newPos; }

vec3 GraphObject::GetSpeed() { return ObSpeed; }
vec3 GraphObject::GetPosition() { return ObPosition; }
