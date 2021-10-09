#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <cstdio>
#include <map>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "resources.h"

using glm::mat4;
using glm::vec3;

int Height = 900;
int Width = 900;

GLuint vaoHandle;


void Display(Shader shader, float angle)
{
	shader.Use();

	//printf("Display(5) Shader ID = %u\n", shader.programHandle);
	
	mat4 rotationMatrix = glm::rotate(mat4(1.0f), angle, vec3(0.0, 0.0, 1.0));
	shader.SetMatrix4("RotationMatrix", rotationMatrix);
	glBindVertexArray(vaoHandle);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void ShaderData(const float *positionData, const float *colorData, int numVertex)
{
	GLuint vboHandle[2];	
	glGenBuffers(2, vboHandle);

	glBindBuffer(GL_ARRAY_BUFFER, vboHandle[0]);
	glBufferData(GL_ARRAY_BUFFER, numVertex*sizeof(float), positionData, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, vboHandle[1]);
	glBufferData(GL_ARRAY_BUFFER, numVertex*sizeof(float), colorData, GL_STATIC_DRAW);

	glGenVertexArrays(1, &vaoHandle);
	glBindVertexArray(vaoHandle);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, vboHandle[0]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	glBindBuffer(GL_ARRAY_BUFFER, vboHandle[1]);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);

}

int main()
{
	GLFWwindow *pWindow;

	if(!glfwInit()) {
		printf("Error, can't init GLFW!\n");
		return -1;
	}

	pWindow = glfwCreateWindow(Width, Height, "Study", NULL, NULL);

	if(pWindow == NULL) {
		printf("Error, can't create window!\n");
		return -1;
	}

	glfwMakeContextCurrent(pWindow);

	if(!gladLoadGL()) {
		printf("Error, can't init GLAD!\n");
		return -1;
	}
	
	Shader triangle = ResourceManager::LoadShader("triangle", "../shaders/rotation.vert", 											"../shaders/rotation.frag");

/*
	if(!(Shaders["Triangle"].IsCompiled())) {
		return -1;
	}
*/
	float angle = M_PI/2;
	float Position[] = {
		-0.5, 0.5, 0.0,
		-0.5, -0.5, 0.0,
		0.5, -0.5, 0.0,
	};
	float Color[] = {
		1.0, 0.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 0.0, 1.0,
	};

//	printf("Main(5) Shader ID = %u\n", (Resources.Shaders["triangle"]).programHandle);

	ShaderData(Position, Color, 9);

	glClearColor(0.2, 0.3, 0.3, 1);

	while(!glfwWindowShouldClose(pWindow)) {
		
		glClear(GL_COLOR_BUFFER_BIT);

		Display(ResourceManager::GetShader("triangle"), angle);
		
		angle += M_PI/100;

//		printf("Ok\n");

		glfwSwapBuffers(pWindow);
		
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
