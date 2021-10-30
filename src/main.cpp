#include "game.h"

const int Height = 1080;
const int Width = 1920;

ResourceManager resources;

Camera camera(glm::vec3(30.0, -30.0, 80.0), glm::vec3(0.0, 0.0, 0.0));

Game game;

static void Keyboard(GLFWwindow *pWindow, int key, int scancode, int action, int modes)
{
	game.KeyboardInput(pWindow, key, scancode, action, modes);
}	

static void Mouse(GLFWwindow *pWindow, double x, double y)
{
	game.MouseInput(y);
}

int main()
{
	GLFWwindow *pWindow;

	if(!glfwInit()) {
		printf("Error, can't init GLFW!\n");
		return -1;
	}

	pWindow = glfwCreateWindow(Width, Height, "Game", NULL, NULL);

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
	glfwSetKeyCallback(pWindow, Keyboard);
	glfwSetCursorPosCallback(pWindow, Mouse);

	FirstLevel First;
	game.Init(First);

	float current_time = 0.0;
	float delta_time = 0.0;
	float last_time = 0.0;


    glViewport(0, 0, Width, Height);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

//	Plane *plane = Load();
/*
	body.initShaderData(QuadData, QuadIndices, 20, 6);
	engine.initShaderData(QuadData, QuadIndices, 20, 6);
	wings.initShaderData(QuadData, QuadIndices, 20, 6);
	tail.initShaderData(QuadData, QuadIndices, 20, 6);

	PhysicObject Test( 5, 0.1, resources.GetShader("plane"), resources.GetTexture("body"),
		vec3(0.0, -1.0, 0.0), vec3(2.2, 1.0, 1.0));

	Test.initShaderData(QuadData, QuadIndices, 20, 6);
*/
	glClearColor(0.21, 0.21, 0.21, 1);

	while(!glfwWindowShouldClose(pWindow)) {
		
		current_time = glfwGetTime();
		delta_time = (current_time - last_time);
		last_time = current_time;

		glClear(GL_COLOR_BUFFER_BIT);

//		plane->Render();
/*
		body.Draw();
		tail.Draw();
		engine.Draw();
		wings.Draw();

		Test.Draw();
*/
		game.UpDate(delta_time, First);

		glfwSwapBuffers(pWindow);
		
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
