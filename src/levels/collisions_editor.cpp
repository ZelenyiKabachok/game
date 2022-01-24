#include "collisions_editor.h"

void CollisionsEditor::Load(const FT_Face& face, int width, int height)
{
    float pVertexes[] = {   
      -1.0, -1.0, 0.0,     0.0, 0.0,
      -1.0,  1.0, 0.0,     0.0, 1.0,
       1.0,  1.0, 0.0,     1.0, 1.0,
       1.0, -1.0, 0.0,     1.0, 0,0
    }; 
    unsigned int pIndices[] {
        0, 1, 2,
        0, 2, 3
    };
     
    ResourceManager& resources = ResourceManager::Instance();
    resources.LoadShader("graphic", "../shaders/sprite.vert" 
								, "../shaders/sprite.frag");
/*
    resources.LoadShader("button", "../shaders/button.vert"
								 , "../shaders/button.frag");
*/
	resources.LoadShader("aabb", "../shaders/aabb.vert"
						       , "../shaders/aabb.frag"
                               , "../shaders/aabb.geom");
    resources.LoadShader("text", "../shaders/text.vert"
                               , "../shaders/text.frag");
    resources.LoadShader("coord", "../shaders/coord.vert"
                                , "../shaders/coord.frag");
    resources.LoadTexture("collis", "../resources/others/collis.jpg");
    resources.LoadTexture("button", "../resources/others/button.png");
    resources.LoadTexture("coord", "../resources/others/coordinate_system.png");
    resources.LoadTexture("color", "../resources/others/color.png");

    pCoordSystem = new Graphic::CoordSystem();
	
    active.sData = "RustyEngine";
    pInterface = new GUI::CollEditGui(pCoordSystem, 1, face, width, height);
	pCamera = new FreeCamera(width, height, glm::vec3(0.0, 0.0, 10.0));

    Physic::PhysicObject *curObj = new Aircraft::RustyBody();
    objects.New("RustyBody", curObj);
    objects.GetPhysic("RustyBody")->InitShaderData(pVertexes, pIndices, 20, 6);
    objects.GetPhysic("RustyBody")->StartDrawCollision();

    curObj = new Aircraft::RustyEngine();
    objects.New("RustyEngine", curObj);
    objects.GetPhysic("RustyEngine")->InitShaderData(pVertexes, pIndices, 20, 6);
    objects.GetPhysic("RustyEngine")->StartDrawCollision();

    curObj = new Aircraft::RustyWings();
    objects.New("RustyWings", curObj);
    objects.GetPhysic("RustyWings")->InitShaderData(pVertexes, pIndices, 20, 6);
    objects.GetPhysic("RustyWings")->StartDrawCollision();

    curObj = new Aircraft::RustyTail();
    objects.New("RustyTail", curObj);
    objects.GetPhysic("RustyTail")->InitShaderData(pVertexes, pIndices, 20, 6);
    objects.GetPhysic("RustyTail")->StartDrawCollision();

    pCoordSystem->Init();

}

void CollisionsEditor::UpDate(float delta_time, const Input& input)
{
    pCamera->Move(delta_time, input.Keys(), input.GetScroll());
    pInterface->Click(input, active);
}

void CollisionsEditor::Render()
{
    objects.GetPhysic(active.sData)->Draw(*pCamera);
    pInterface->Render(*pCamera);
}

CollisionsEditor::~CollisionsEditor()
{
    delete pCamera;
    delete pCoordSystem;
}

