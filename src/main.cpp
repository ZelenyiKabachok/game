#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <cstdio>
#include <map>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "resources.h"
#include "camera.h"
#include "sprite.h"

using glm::mat4;
using glm::vec3;

int Height = 1080;
int Width = 1920;

Camera camera(vec3(0.0, 0.0, 4.0), 0.05, 0.0, 0.05);

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

	ResourceManager resources;
	
	resources.LoadShader("triangle", "../shaders/sprite.vert", 
									"../shaders/sprite.frag");

//	resources.LoadTexture("triangle1", "../resourses/coblestone.jpg");

	resources.LoadTexture("triangle", "../resourses/cxx.png");

	resources.GetShader("triangle").Use();
	resources.GetShader("triangle").SetInt("ourTexture", 0);
//	resources.GetShader("triangle").SetInt("ourTexture2", 1);

	Sprite Quad(resources.GetShader("triangle"));

	glClearColor(0.2, 0.3, 0.3, 1);

	float current_time = 0.0;
	float delta_time = 0.0;
	float last_time = 0.0;

	float trAngle = 0;//M_PI/3;
	vec3 TrPosition = { 2.0, -1.0, 0.0 };
	vec3 TrSize = { 0.5, 0.5, 0.5 };
	vec3 TrRotateVector = { 0.0, 1.0, 0.0};	

	while(!glfwWindowShouldClose(pWindow)) {
		
		current_time = glfwGetTime();
		delta_time = current_time - last_time;
		last_time = current_time;


		glfwSetKeyCallback(pWindow, Keyboard);
		glClear(GL_COLOR_BUFFER_BIT);

		Quad.Draw(resources.GetTexture("triangle"), delta_time, TrPosition,
								TrSize, TrRotateVector, trAngle);

		//trAngle += M_PI/1000;

		glfwSwapBuffers(pWindow);
		
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
