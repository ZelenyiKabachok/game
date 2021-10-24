#include "first_level.h"

void FirstLevel::Load()
{
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
/*
	GrObjects = new PhysicObject[2] = {
	Paral(10, 0.1, resources.GetShader("triangle"),
	resources.GetTexture("paral")vec3(-1.0, 1.0, 0.0), 
	vec3(0.5, 0.5, 0.5), vec3(-1.0, 7.0, 0.0),);

	};
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

	PhObjects = {
	{5, 0.1, resources.GetShader("triangle"), resources.GetTexture("triangle")},

	{10, 0.1, resources.GetShader("triangle"),
		resources.GetTexture("paral"), vec3(-1.0, 1.0, 0.0), 
		vec3(0.5, 0.5, 0.5), vec3(-1.0, 7.0, 0.0)}

	};



	PhObjects[0].initShaderData(QuadData, QuadIndices, 20, 6);
	PhObjects[1].initShaderData(ParalData, ParalIndices, 20, 6);
}

void FirstLevel::UpDate(float delta_time)
{
	PhObjects[0].AttractAndMove(delta_time);

	PhObjects[1].AttractAndMove(delta_time);
}

