#include "game.h"

int Height = 1080;
int Width = 1920;

ResourceManager resources;

Camera camera(glm::vec3(0.0, 0.0, 30.0), glm::vec3(0.0, 0.0, 0.0));

Game game;

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

	FirstLevel First;
	game.Init(First);
/*
	resources.LoadShader("triangle", "../shaders/sprite.vert", 
									"../shaders/sprite.frag");

	resources.LoadTexture("triangle", "../resourses/cxx.png");
	resources.LoadTexture("paral", "../resourses/wod2.jpg");

	resources.GetShader("triangle").Use();
	resources.GetShader("triangle").SetInt("ourTexture", 0);

	std::vector<PhysicObject> PhObjects = {
	{5, 0.1, resources.GetShader("triangle"), resources.GetTexture("triangle")},
	{10, 0.1, resources.GetShader("triangle"),
		resources.GetTexture("paral"), vec3(-1.0, 1.0, 0.0), 
		vec3(0.5, 0.5, 0.5), vec3(-1.0, 7.0, 0.0)}
	};




	GraphObject Quad(resources.GetShader("triangle"), resources.GetTexture("triangle"),
					vec3(1.0, -1.0, 0.0), vec3(0.8, 0.8, 0.8), vec3(0.0, 0.08, 0.0));
*/
/*
	GrObjects = new PhysicObject[2] = {
	Paral(10, 0.1, resources.GetShader("triangle"),
	resources.GetTexture("paral")vec3(-1.0, 1.0, 0.0), 
	vec3(0.5, 0.5, 0.5), vec3(-1.0, 7.0, 0.0),);

	};

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
	

	PhObjects[0].initShaderData(QuadData, QuadIndices, 20, 6);
	PhObjects[1].initShaderData(ParalData, ParalIndices, 20, 6);
*/
	float current_time = 0.0;
	float delta_time = 0.0;
	float last_time = 0.0;

	glClearColor(0.21, 0.21, 0.21, 1);

	while(!glfwWindowShouldClose(pWindow)) {
		
		current_time = glfwGetTime();
		delta_time = (current_time - last_time);
		last_time = current_time;

		glfwSetKeyCallback(pWindow, Keyboard);
		glClear(GL_COLOR_BUFFER_BIT);

		game.UpDate(delta_time, First);

/*
		PhObjects[0].AttractAndMove(delta_time);

		PhObjects[1].AttractAndMove(delta_time);
*/

		glfwSwapBuffers(pWindow);
		
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
