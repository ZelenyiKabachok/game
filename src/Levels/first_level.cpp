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
		vec3(118.0, 2.5, -70.0), vec3(65*2.92, 65*1.0, 1.0) }
	};


	PhObjects = {
	{ 5, 0.1, resources.GetShader("plane"), resources.GetTexture("tail"),
		vec3(0.0, -1.0, 0.0), vec3(2.2, 1.0, 1.0) },
	};

	RustyBody body(resources.GetShader("plane"));
	RustyEngine engine(resources.GetShader("plane"));
	RustyWings wings(resources.GetShader("plane"));
	RustyTail tail(resources.GetShader("plane"));


	plane = new Plane(body, engine, wings, tail, vec3(30.0, 10.0, 0.0));


	GrObjects[0].initShaderData(QuadData, QuadIndices, 20, 6);
	//PhObjects[0].initShaderData(QuadData, QuadIndices, 20, 6);

	camera.FocusOnTheObject(&(plane->GetBody()));

}

void FirstLevel::UpDate(float delta_time, const bool *keys, const float angle)
{
	plane->Fly(delta_time, keys[W], keys[S], angle);	
	plane->PrintPlaneState();
}

void FirstLevel::Render()
{
	GrObjects[0].Draw();
	plane->Render();
//	/body->Draw();
	//PhObjects[0].Draw();
}

FirstLevel::~FirstLevel()
{
	GrObjects.clear();
	PhObjects.clear();
//	plane.clear();
	delete plane;
}
