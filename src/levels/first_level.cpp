#include "first_level.h"

void FirstLevel::Load()
{
    ResourceManager& resources = ResourceManager::Instance();
	resources.LoadShader("plane", "../shaders/sprite.vert", 
								  "../shaders/sprite.frag");
	resources.LoadShader("aabb", "../shaders/aabb.vert", 
						"../shaders/aabb.frag", "../shaders/aabb.geom");
	
	resources.LoadTexture("back", "../resources/backgrounds/Back7.jpg");
	resources.LoadTexture("box", "../resources/others/wooden_container1.jpg");
	resources.LoadTexture("collis", "../resources/others/collis.jpg");
    
//	resources.GetShader("plane").Use();
//	resources.GetShader("plane").SetInt("ourTexture", 0);

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

	pCamera = new Camera(glm::vec3(0.0, 0.0, 80.0), glm::vec3(0.0, 0.0, 0.0));

	Graphic::GraphObject grobj[] = {
		{ resources.GetShader("plane"), resources.GetTexture("back")
		, glm::vec3(118.0, 2.5, 0.0), glm::vec3(50*2.92, 50*1.0, 1.0) },
	};

	Physic::PhysicObject phobj[] = {
	    { 5, 0.1, resources.GetShader("plane"), resources.GetTexture("box")
		, glm::vec3(0.0, -1.0, 0.0), glm::vec3(4.0, 4.0, 1.0) }, 

	    { 200, 2, resources.GetShader("plane"), resources.GetTexture("box")
		, glm::vec3(10.0, 20.0, 0.0), glm::vec3(2.0, 2.0, 1.0), glm::vec3(0)
		, glm::vec3(0.0, 0.0, 1.0), (float)(M_PI/3) },

	    { 50, 8, resources.GetShader("plane"), resources.GetTexture("box")
		, glm::vec3(20.0, 1.0, 0.0), glm::vec3(5.0, 5.0, 1.0) },
	};

	GrObjects.Create(grobj, 1);
	PhObjects.Create(phobj, 3);


	pPlane = new Aircraft::Plane(Aircraft::RUST_BODY, Aircraft::RUST_ENGINE
                        , Aircraft::RUST_WINGS, Aircraft::RUST_TAIL
						, glm::vec3(-50.0, 0.0, 0.0), glm::vec3(30.0, 0.0, 0.0)
						, CollObjects, resources.GetShader("plane"));
	pPlane->InitDrawColl(resources.GetShader("plane")
                        , resources.GetShader("aabb")
                        , resources.GetTexture("collis"));

	GrObjects[0].initShaderData(QuadData, QuadIndices, 20, 6);

	PhObjects[0].initShaderData(QuadData, QuadIndices, 20, 6);
	PhObjects[1].initShaderData(QuadData, QuadIndices, 20, 6);
    printf("Ok\n");
	//PhObjects[2].initShaderData(TriangleData, vec3(1.0f, 1.0f, 1.0f), 8);

	pCamera->FocusOnTheObject(&(pPlane->GetBody()));
}

void FirstLevel::UpDate(float delta_time, const bool *keys, const float angle)
{

	pCamera->Follow(delta_time);

	pPlane->Fly(delta_time, keys[W], keys[S], angle);	

	PhObjects[0].Move(delta_time);
	PhObjects[1].Move(delta_time);
	PhObjects[2].Move(delta_time);

}

void FirstLevel::Render()
{
	GrObjects[0].Draw(*pCamera);
	pPlane->Render(*pCamera);
	PhObjects[0].Draw(*pCamera);
	PhObjects[1].Draw(*pCamera);

//	PhObjects[2].DrawContour(*camera, 20);
}

FirstLevel::FirstLevel() {}

FirstLevel::~FirstLevel()
{
	pCamera->CancelFocus();
	delete pPlane;
}
