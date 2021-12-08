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
    objects.New("body", new Aircraft::RustyBody(resources.GetShader("plane")));
    objects.GetBody("body")->initShaderData(vertexes, indices, 20, 6);
    objects.GetBody("body")->StartDrawCollision(resources.GetShader("plane")
                                              , resources.GetShader("aabb")
                                              , resources.GetTexture("collis"));
                                                
}

void CollisionsEditor::UpDate(float delta_time, const bool *keys
                            , const float angle, float scroll)
{
    pCamera->Move(delta_time, keys, scroll);
    objects.GetBody("body")->Graphic::GraphObject::Move(delta_time);
}

void CollisionsEditor::Render()
{
    objects.GetBody("body")->Draw(*pCamera);
}

CollisionsEditor::~CollisionsEditor()
{
    delete pCamera;
}

