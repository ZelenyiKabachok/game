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
	
	pCamera = new FreeCamera(glm::vec3(0.0, 0.0, 10.0));
    Objects.NewLast(Aircraft::RustyBody(resources.GetShader("plane")));
    Objects[0].initShaderData(vertexes, indices, 20, 6);
}

void CollisionsEditor::UpDate(float delta_time, const bool *keys
                            , const float angle, float scroll)
{
    pCamera->Move(delta_time, keys, scroll);
    Objects[0].Move(delta_time);
}

void CollisionsEditor::Render()
{
    Objects[0].Draw(*pCamera);
}

CollisionsEditor::~CollisionsEditor()
{
    delete pCamera;
}

