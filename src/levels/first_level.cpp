#include "first_level.h"

void FirstLevel::Load()
{
    ResourceManager& resources = ResourceManager::Instance();
	Graphic::Shader& planeShader = resources.LoadShader("plane"
                                , "../shaders/sprite.vert"
								, "../shaders/sprite.frag");
	resources.LoadShader("aabb", "../shaders/aabb.vert", 
						"../shaders/aabb.frag", "../shaders/aabb.geom");
	
	resources.LoadTexture("back", "../resources/backgrounds/Back7.jpg");
	resources.LoadTexture("box", "../resources/others/wooden_container1.jpg");
	resources.LoadTexture("collis", "../resources/others/collis.jpg");

    objects.New("RustyBody", new Aircraft::RustyBody());
    objects.New("RustyEngine", new Aircraft::RustyEngine());
    objects.New("RustyWings", new Aircraft::RustyWings());
    objects.New("RustyTail", new Aircraft::RustyTail());

    objects.New("Back", new Graphic::GraphObject(planeShader
        , resources.GetTexture("back"), glm::vec3(118.0, 2.5, 0.0)
        , glm::vec3(50*2.92, 50*1.0, 1.0)));
    objects.New("1", new Physic::PhysicObject(
          "../resources/collisions/box.collis", 5, 0.1
        , resources.GetShader("plane"), resources.GetTexture("box")
		, glm::vec3(0.0, -1.0, 0.0), glm::vec3(1.0, 1.0, 1.0))); 
    objects.New("2", new Physic::PhysicObject(
          "../resources/collisions/box.collis", 200, 2
        , resources.GetShader("plane"), resources.GetTexture("box")
		, glm::vec3(10.0, 20.0, 0.0), glm::vec3(1.0, 1.0, 1.0), glm::vec3(0)
		, glm::vec3(0.0, 0.0, 1.0), (float)(M_PI/3)));

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

    objects.GetBody("RustyBody")->initShaderData(QuadData, QuadIndices, 20, 6);
    objects.GetEngine("RustyEngine")->initShaderData(QuadData, QuadIndices, 20, 6);
    objects.GetWings("RustyWings")->initShaderData(QuadData, QuadIndices, 20, 6);
    objects.GetTail("RustyTail")->initShaderData(QuadData, QuadIndices, 20, 6);
    objects.GetGraphic("Back")->initShaderData(QuadData, QuadIndices, 20, 6);
    objects.GetPhysic("1")->initShaderData(QuadData, QuadIndices, 20, 6);
    objects.GetPhysic("2")->initShaderData(QuadData, QuadIndices, 20, 6);


	pCamera = new GameCamera(glm::vec3(0.0, 0.0, 40.0), glm::vec3(0.0, 0.0, 0.0));

	pPlane = new Aircraft::Plane(objects.GetBody("RustyBody")
                        , objects.GetEngine("RustyEngine")
                        , objects.GetWings("RustyWings")
                        , objects.GetTail("RustyTail")
						, glm::vec3(-50.0, 0.0, 0.0), glm::vec3(30.0, 0.0, 0.0)
						, CollObjects);
	pPlane->StartDrawCollision();
    objects.GetPhysic("1")->StartDrawCollision();
    objects.GetPhysic("2")->StartDrawCollision();
    
	pCamera->FocusOnTheObject(&(pPlane->GetBody()));

}

void FirstLevel::UpDate(float delta_time, const bool *keys
                , const float angle, float scroll)
{

//	pCamera->Follow(delta_time);

	pPlane->Fly(delta_time, keys['W'], keys['S'], angle);	

	objects.GetPhysic("1")->Move(delta_time);
	objects.GetPhysic("2")->Move(delta_time);
}

void FirstLevel::Render()
{
    objects.GetGraphic("Back")->Draw(*pCamera);
	pPlane->Render(*pCamera);
	objects.GetPhysic("1")->/*Graphic::GraphObject::*/Draw(*pCamera);
	objects.GetPhysic("2")->/*Graphic::GraphObject::*/Draw(*pCamera);
}

FirstLevel::~FirstLevel()
{
	pCamera->CancelFocus();
	delete pPlane;
}
