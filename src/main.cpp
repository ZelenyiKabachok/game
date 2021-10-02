#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cstdio>
#include "shader.h"

int Height = 800;
int Width = 1800;

int main()
{
	GLFWwindow *pWindow;

	if(!glfwInit()) {
		printf("Error, can't init GLFW!\n");
		return -1;
	}

	pWindow = glfwCreateWindow(Height, Width, "Study", NULL, NULL);

	if(pWindow == NULL) {
		printf("Error, can't create window!\n");
		return -1;
	}

	glfwMakeContextCurrent(pWindow);

	if(!gladLoadGL()) {
		printf("Error, can't init GLAD!\n");
		return -1;
	}

	Shader triangle("basic.vert", "basic.frag");

	float Position[] = {
		0.0, 0.5, 0.0,
		-0.5, -0.5, 0.0,
		0.5, -0.5, 0.0,
	};
	float Color[] = {
		1.0, 0.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 0.0, 1.0,
	};

	triangle.Params(Position, Color, 9);
	glClearColor(0.8, 0.8, 0.8, 1);

	while(!glfwWindowShouldClose(pWindow)) {
		
		glClear(GL_COLOR_BUFFER_BIT);

		triangle.Render();

		glfwSwapBuffers(pWindow);
		
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
