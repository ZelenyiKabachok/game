#include "collisions_editor.h"

void CollisionsEditor::Load()
{
    float vertexes[] = {    
      -1.0, -1.0, 0.0,     0.0, 0.0,
      -1.0,  1.0, 0.0,     0.0, 1.0,
       1.0,  1.0, 0.0,     1.0, 1.0,
       1.0, -1.0, 0.0,     1.0, 0,0
    }; 
    unsigned int indices[] {
        0, 1, 2,
        0, 2, 3
    };
     
    ResourceManager& resources = ResourceManager::Instance();
    resources.LoadShader("plane", "../shaders/sprite.vert", 
								  "../shaders/sprite.frag");
	resources.LoadShader("aabb", "../shaders/aabb.vert", 
						"../shaders/aabb.frag", "../shaders/aabb.geom");
    resources.LoadTexture("collis", "../resources/others/collis.jpg");
	
	pCamera = new FreeCamera(glm::vec3(0.0, 0.0, 10.0));
    Physic::PhysicObject *p = new Aircraft::RustyBody();
    objects.New("RustyBody", p);
    objects.GetPhysic("RustyBody")->initShaderData(vertexes, indices, 20, 6);
    objects.GetPhysic("RustyBody")->StartDrawCollision();

    p = new Aircraft::RustyEngine();
    objects.New("RustyEngine", p);
    objects.GetPhysic("RustyEngine")->initShaderData(vertexes, indices, 20, 6);
    objects.GetPhysic("RustyEngine")->StartDrawCollision();

    p = new Aircraft::RustyWings();
    objects.New("RustyWings", p);
    objects.GetPhysic("RustyWings")->initShaderData(vertexes, indices, 20, 6);
    objects.GetPhysic("RustyWings")->StartDrawCollision();

    p = new Aircraft::RustyTail();
    objects.New("RustyTail", p);
    objects.GetPhysic("RustyTail")->initShaderData(vertexes, indices, 20, 6);
    objects.GetPhysic("RustyTail")->StartDrawCollision();
}

void CollisionsEditor::UpDate(float delta_time, const bool *keys
                            , const float angle, float scroll)
{
    pCamera->Move(delta_time, keys, scroll);
    objects.GetPhysic(sActive)->Graphic::GraphObject::Move(delta_time);
}

void CollisionsEditor::Render()
{
    objects.GetPhysic(sActive)->Draw(*pCamera);
}

CollisionsEditor::~CollisionsEditor()
{
    delete pCamera;
}

