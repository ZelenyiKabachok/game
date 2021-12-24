#include "game.h"

Game game;

void key_callback(GLFWwindow *pWindow, int key, int scancode, int action
                                                            , int modes)
{
	if(key == GLFW_KEY_ESCAPE)
    { glfwSetWindowShouldClose(pWindow, GLFW_TRUE); }
	game.KeyboardInput(key, scancode, action, modes);
}	

void cursor_position_callback(GLFWwindow *pWindow, double x, double y)
{
	game.MousePosition(x, y);
}

void mouse_button_callback(GLFWwindow *pWindow, int button, int action
                                                          , int modes)
{
    game.MouseButton(button, action, modes);
}

void scroll_callback(GLFWwindow *pWindow, double xOffset, double yOffset)
{
    game.ScrollInput(yOffset);
} 

int main(int argc, char **argv)
{
	GLFWwindow *pWindow;

	if(!glfwInit()) {
		fprintf(stderr, "Error, can't init GLFW!\n");
		return -1;
	}

	//pWindow = glfwCreateWindow(Width, Height, "Game", NULL, NULL);
    const GLFWvidmode *vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    int width, height;
    width = vidmode->width;
    height = vidmode->height;
    
    //glfwGetWindowSize(&Width, &Height);
    pWindow = glfwCreateWindow(width, height, "Game"
                            , glfwGetPrimaryMonitor(), nullptr);
	if(pWindow == NULL) {
		fprintf(stderr, "Error, can't create window!\n");
		return -1;
	}

	glfwMakeContextCurrent(pWindow);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
		fprintf(stderr, "Error, can't init GLAD!\n");
        return -1;
    }

    FT_Library ft;
    if(FT_Init_FreeType(&ft)) {
        fprintf(stderr, "Error init FreeType library\n");
        return -1;
    }
    FT_Face face;
    if(FT_New_Face(ft, "../resources/fronts/front.ttf", 0, &face)) {
        fprintf(stderr, "Error load front\n");
        return -1;
    }

	glfwSetKeyCallback(pWindow, key_callback);
	glfwSetCursorPosCallback(pWindow, cursor_position_callback);
    glfwSetScrollCallback(pWindow, scroll_callback);
    glfwSetMouseButtonCallback(pWindow, mouse_button_callback);

    ILevel *Level = game.ChooseLevel(pWindow, argc, argv);

  	game.Init(*Level, width, height);

	float current_time = 0.0;
	float delta_time = 0.0;
	float last_time = 0.0;

    glViewport(0, 0, width, height);
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
