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

GLuint VAO;

void Display(Shader shader, Texture2D texture1, Texture2D texture2, float angleModel)
{
	shader.Use();

	glActiveTexture(GL_TEXTURE0);
	texture1.Bind();
	glActiveTexture(GL_TEXTURE1);
	texture2.Bind();

	mat4 Model = glm::rotate(mat4(1.0f), angleModel, vec3(1.0, 0.0, 0.0));
	mat4 View = glm::translate(mat4(1.0f), vec3(0.0, 0.0, -3.0));
	mat4 Projection = glm::perspective((float)(M_PI/4), 900.0f / 900.0f, 0.1f, 100.0f);

	shader.SetMatrix4("ModelMatrix", Model);
	shader.SetMatrix4("ViewMatrix", View);
	shader.SetMatrix4("ProjectionMatrix", Projection);

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

}

static void Keyboard(GLFWwindow *pWindow, int key, int scancode, int action, int modes)
{
	if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(pWindow, GLFW_TRUE);
	}
}	

void ShaderData()
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
	
    // Сначала связываем объект вершинного массива, затем связываем и устанавливаем вершинный буфер(ы), и затем конфигурируем вершинный атрибут(ы)
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

    // Обратите внимание, что данное действие разрешено, вызов glVertexAttribPointer() зарегистрировал VBO как привязанный вершинный буферный объект для вершинного атрибута, так что после этого мы можем спокойно выполнить отвязку
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // помните: не отвязывайте EBO, пока VАО активен, поскольку связанного объект буфера элемента хранится в VАО; сохраняйте привязку EBO.
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // Вы можете отменить привязку VАО после этого, чтобы другие вызовы VАО случайно не изменили этот VAO (но подобное довольно редко случается).
    // Модификация других VAO требует вызов glBindVertexArray(), поэтому мы обычно не снимаем привязку VAO (или VBO), когда это не требуется напрямую
    glBindVertexArray(0);
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
	
	resources.LoadShader("triangle", "../shaders/tex.vert", "../shaders/tex.frag");

	resources.LoadTexture("triangle1", "../resourses/coblestone.jpg");

	resources.LoadTexture("triangle2", "../resourses/cxx.png");

	float angleModel = -M_PI/4;

	resources.GetShader("triangle").Use();
	resources.GetShader("triangle").SetInt("ourTexture1", 0);
	resources.GetShader("triangle").SetInt("ourTexture2", 1);

	ShaderData();
	glClearColor(0.2, 0.3, 0.3, 1);

	while(!glfwWindowShouldClose(pWindow)) {
		
		glfwSetKeyCallback(pWindow, Keyboard);
		glClear(GL_COLOR_BUFFER_BIT);

		Display(resources.GetShader("triangle"), resources.GetTexture("triangle1"),
				resources.GetTexture("triangle2"), angleModel);
		
	//	angleModel += M_PI/100;

		glfwSwapBuffers(pWindow);
		
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
