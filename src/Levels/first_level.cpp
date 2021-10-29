#include "first_level.h"

void FirstLevel::Load()
{
	resources.LoadShader("plane", "../shaders/sprite.vert", 
									"../shaders/sprite.frag");

/*
	resources.LoadTexture("body", "../resources/Bodies/Rusty_body.png");
	resources.LoadTexture("engine", "../resources/Engines/Rusty_engine.png");
	resources.LoadTexture("wings", "../resources/Wings/Rusty_wings.png");
	resources.LoadTexture("tail", "../resources/Tails/Rusty_tail.png");
*/
	resources.LoadTexture("back", "../resources/Backgrounds/Back7.jpg");

	resources.GetShader("plane").Use();
	resources.GetShader("plane").SetInt("ourTexture", 0);

	float QuadData[] = {
	   -1.0, -1.0, 0.0,		0.0, 0.0,
	   -1.0,  1.0, 0.0,		0.0, 1.0,
	   	1.0,  1.0, 0.0,		1.0, 1.0,
	   	1.0, -1.0, 0.0,		1.0, 0,0
	};
	unsigned int QuadIndices[] {
		0, 1, 2,
		0, 2, 3
	};

	GrObjects = {
	{ resources.GetShader("plane"), resources.GetTexture("back"),
		vec3(0.0, 0.0, -70.0), vec3(35*2.92, 35*1.0, 35*1.0) }
	};

/*
	PhObjects = {
	{ 5, 0.1, resources.GetShader("triangle"), resources.GetTexture("plane"),
		vec3(0.0, -1.0, 0.0), vec3(2.2, 1.0, 1.0) },
	};
*/
	GrObjects[0].initShaderData(QuadData, QuadIndices, 20, 6);
}

void FirstLevel::UpDate(float delta_time, const bool *keys, const float angle)
{
	
}

void FirstLevel::Render()
{
	GrObjects[0].Draw();
}

FirstLevel::~FirstLevel()
{
	PhObjects.clear();
}
