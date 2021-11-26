#include "shape_draw.h"

ShapeDraw::ShapeDraw(const Shader& sh, const Texture2D& tex, 
						 const vec3& pos, const vec3& size, const vec3& speed,
						 const vec3& slVec, const float slAng)
					: GraphObject(sh, tex, pos, size, speed, slVec, slAng)
{}

void ShapeDraw::initShaderData(const float *Data, const glm::vec3& Color, 
								 unsigned int vertexes, GLenum DrawType)
{
	type = DrawType;
	points = vertexes;
	color = Color;
	unsigned int VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
	
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, 3*vertexes * sizeof(float), Data, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);
    glEnableVertexAttribArray(0);
}

void ShapeDraw::initShaderData(const glm::vec2 *Data, const glm::vec3& Color,
								 unsigned int vertexes, GLenum DrawType)
{
	float arrData[vertexes*3] = {0.0};
	for(unsigned int i = 0, j = 0; i < vertexes; i++, j += 3) {
		arrData[j] = Data[i].x;
		arrData[j+1] = Data[i].y;
	}
	initShaderData(arrData, Color, vertexes, DrawType);
}

void ShapeDraw::Draw(const Camera& camera, float width) const
{
	shader.Use();
	glActiveTexture(GL_TEXTURE0);
	texture.Bind();

	glm::mat4 ModelMatrix = PositionMatrix * RotateMatrix * SizeMatrix;
	shader.SetVector3("Color", color);
	shader.SetMatrix4("CameraMatrix", camera.GetCameraMatrix());
	shader.SetMatrix4("ModelMatrix", ModelMatrix);
	glBindVertexArray(VAO);

	glLineWidth(width);
	glPointSize(width);
	glDrawArrays(type, 0, points);
	//glDrawElements(type, points, GL_UNSIGNED_INT, 0);
}

void ShapeDraw::Move(const char *uniPos, const vec3& pos)
{
	shader.SetVector3(uniPos, pos);
}
