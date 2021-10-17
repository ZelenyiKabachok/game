#include "sprite.h"

extern Camera camera;

Sprite::Sprite(const Shader& sh) : shader(sh)
{ initShaderData(); }

void Sprite::Draw(const Texture2D& texture, const float delta_time, 
	const vec3& position, const vec3& size, const vec3& rotateVector, 
												const float angle)
{
	shader.Use();

	glActiveTexture(GL_TEXTURE0);
	texture.Bind();

	glm::mat4 Camera = camera.MoveCamera(delta_time);
	glm::mat4 Rotate = glm::rotate(mat4(1.0f), angle, rotateVector);
	glm::mat4 Position = glm::translate(glm::mat4(1.0f), position);
	glm::mat4 Size = glm::scale(mat4(1.0f), size);

	glm::mat4 Model = Position * Rotate * Size;

	shader.SetMatrix4("CameraMatrix", Camera);
	shader.SetMatrix4("ModelMatrix", Model);
	
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Sprite::initShaderData()
{
	float Data[] = {
	   -0.8, -0.8, 0.0,		1.0, 0.7, 0.0, 	0.0, 0.0,
	   -0.8,  0.8, 0.0,		1.0, 0.7, 0.0,	0.0, 1.0,
	   	0.8,  0.8, 0.0,		1.0, 0.7, 0.0,  1.0, 1.0,
	   	0.8, -0.8, 0.0,		1.0, 0.7, 0.0,  1.0, 0,0
	};
	unsigned int indices[] {
		0, 1, 2,
		0, 2, 3
	};

	unsigned int VBO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
	
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Data), Data, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), NULL);
    glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
												(void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
												(void*)(6*sizeof(float)));
	glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
}
