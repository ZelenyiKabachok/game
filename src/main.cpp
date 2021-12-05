#include "game.h"

const int Height = 1080;
const int Width = 1920;

Game game;


static void keyboard(GLFWwindow *pWindow, int key, int scancode, int action
                                                               , int modes)
{
	game.KeyboardInput(pWindow, key, scancode, action, modes);
}	

static void mouse(GLFWwindow *pWindow, double x, double y)
{
	game.MouseInput(y);
}

static void scroll(GLFWwindow *pWindow, double xOffset, double yOffset)
{
    game.ScrollInput(yOffset);
} 

int main(int argc, char **argv)
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

	glfwSetKeyCallback(pWindow, keyboard);
	glfwSetCursorPosCallback(pWindow, mouse);
    glfwSetScrollCallback(pWindow, scroll);

    ILevel *Level = game.ChooseLevel(pWindow, argc, argv);

	game.Init(*Level);

	float current_time = 0.0;
	float delta_time = 0.0;
	float last_time = 0.0;

    glViewport(0, 0, Width, Height);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glClearColor(0.21, 0.21, 0.21, 1);

	while(!glfwWindowShouldClose(pWindow)) {

	   		
		current_time = glfwGetTime();
		delta_time = (current_time - last_time);
		last_time = current_time;

		glClear(GL_COLOR_BUFFER_BIT);

		game.UpDate(delta_time, *Level);

		glfwSwapBuffers(pWindow);
		
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
