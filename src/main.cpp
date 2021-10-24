#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <cstdio>
#include <map>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "loads.h"
#include "objects.h"
#include "camera.h"


using glm::mat4;
using glm::vec3;

int Height = 1080;
int Width = 1920;

Camera camera(vec3(0.0, 0.0, 30.0), vec3(0.0, 0.0, 0.0));

static void Keyboard(GLFWwindow *pWindow, int key, int scancode, int action, int modes)
{
	if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(pWindow, GLFW_TRUE);
	}
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

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
		printf("Error, can't init GLAD!\n");
        return -1;
    }

	glfwSetInputMode(pWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	ResourceManager resources;
	
	resources.LoadShader("triangle", "../shaders/sprite.vert", 
									"../shaders/sprite.frag");

	resources.LoadTexture("triangle", "../resourses/cxx.png");
	resources.LoadTexture("paral", "../resourses/wod2.jpg");

	resources.GetShader("triangle").Use();
	resources.GetShader("triangle").SetInt("ourTexture", 0);

/*
	GraphObject Quad(resources.GetShader("triangle"), resources.GetTexture("triangle"),
					vec3(1.0, -1.0, 0.0), vec3(0.8, 0.8, 0.8), vec3(0.0, 0.08, 0.0));
*/

	PhysicObject Quad(5, 0.1, resources.GetShader("triangle"), 
						resources.GetTexture("triangle"));

/*
	PhysicObject Paral(10, 0.1, resources.GetShader("triangle"),
									resources.GetTexture("paral")
	vec3(-1.0, 1.0, 0.0), vec3(0.5, 0.5, 0.5), vec3(-1.0, 7.0, 0.0),);
*/

	float QuadData[] = {
	   -0.8, -0.8, 0.0,		0.0, 0.0,
	   -0.8,  0.8, 0.0,		0.0, 1.0,
	   	0.8,  0.8, 0.0,		1.0, 1.0,
	   	0.8, -0.8, 0.0,		1.0, 0,0
	};
	unsigned int QuadIndices[] {
		0, 1, 2,
		0, 2, 3
	};
	
	/*
	float ParalData[] = {
		-0.8, -0.8, 0.0,	0.0, 0.0,
		 0.0,  0.8, 0.0,	0.0, 0.8,
		 0.8,  0.8, 0.0,	1.0, 1.0,
		 0.0, -0.8, 0.0,	1.0, 0.0
	};
	unsigned int ParalIndices[] {
		0, 1, 2,
		0, 2, 3,
	};	
	*/

	Quad.initShaderData(QuadData, QuadIndices, 20, 6);
	//Paral.initShaderData(ParalData, ParalIndices, 20, 6);

	float current_time = 0.0;
	float delta_time = 0.0;
	float last_time = 0.0;

	float QAngle = 0;

	glClearColor(0.25, 0.25, 0.25, 1);

	while(!glfwWindowShouldClose(pWindow)) {
		
		current_time = glfwGetTime();
		delta_time = (current_time - last_time);
		last_time = current_time;

		glfwSetKeyCallback(pWindow, Keyboard);
		glClear(GL_COLOR_BUFFER_BIT);

		camera.MoveCamera(delta_time);

		Quad.AttractAndMove(delta_time);

//		Paral.AttractAndMove(delta_time);

		QAngle += M_PI/80;

		glfwSwapBuffers(pWindow);
		
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
