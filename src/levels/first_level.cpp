#include "first_level.h"

void FirstLevel::Load()
{
/*
	resources.LoadShader("plane", "../shaders/sprite.vert", 
								  "../shaders/sprite.frag");
//	resources.LoadShader("collis", "../shaders/sprite.vert", 
//						"../shaders/sprite.frag", "../shaders/aabb.geom");
	
	resources.LoadTexture("back", "../resources/Backgrounds/Back7.jpg");
	resources.LoadTexture("box", "../resources/Others/wooden_container1.jpg");
	resources.LoadTexture("collis", "../resources/Others/collis.jpg");
		

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

	float TriangleData[] = {
	   -1.0,  0.0, 0.0,
	   -0.7,  0.5, 0.0,
	    0.0,  1.0, 0.0,
		0.7,  0.5, 0.0,
		1.0,  0.0, 0.0,
	    0.7, -0.5, 0.0,
		0.0, -1.0, 0.0,
	   -0.7, -0.5, 0.0,
	};
*/
	glm::vec2 AABB[2] = {
		glm::vec2(-1.0, -1.0),
		glm::vec2(1.0, 1.0),
	};

    glm::vec2 triang[3] = {
        glm::vec2(0.0, 1.0),
        glm::vec2(-1.0, -1.0),
        glm::vec2(1.0, -1.0),
    };
    Shape **shape = new Shape*;
    *shape = new Shape(triang, glm::vec2(0.0, 0.0), 3);
    Collis.Init(shape, 1, AABB);

	camera = new Camera(glm::vec3(0.0, 0.0, 10.0), glm::vec3(0.0, 0.0, 0.0));
/*
	GraphObject grobj[] = {
		{ resources.GetShader("plane"), resources.GetTexture("back"),
		vec3(118.0, 2.5, 0.0), vec3(50*2.92, 50*1.0, 1.0) },

		{ resources.GetShader("collis"), resources.GetTexture("collis"),
		vec3(0.0) },

	};

	PhysicObject phobj[] = {
	{ 5, 0.1, resources.GetShader("plane"), resources.GetTexture("box"),
		vec3(0.0, -1.0, 0.0), vec3(4.0, 4.0, 1.0) }, 

	{ 200, 2, resources.GetShader("plane"), resources.GetTexture("box"),
		vec3(10.0, 20.0, 0.0), vec3(2.0, 2.0, 1.0), vec3(0),
		vec3(0.0, 0.0, 1.0), (float)(M_PI/3) },

	{ 50, 8, resources.GetShader("plane"), resources.GetTexture("box"),
		vec3(20.0, 1.0, 0.0), vec3(5.0, 5.0, 1.0) },
	};

	GrObjects.Create(grobj, 2);
	PhObjects.Create(phobj, 3);


	plane = new Plane(RUST_BODY, RUST_ENGINE, RUST_WINGS, RUST_TAIL,
						vec3(-50.0, 0.0, 0.0), vec3(30.0, 0.0, 0.0), 
						CollObjects, resources.GetShader("plane"));


	//plane->PrepareForDraw(resources.GetShader("plane"), resources.GetTexture("collis"));

//	GrObjects[0].initShaderData(QuadData, QuadIndices, 20, 6);
	GrObjects[1].initShaderData(AABB, vec3(1.0, 0.0, 0.0), 2, GL_LINES);


	PhObjects[0].initShaderData(QuadData, QuadIndices, 20, 6);
	PhObjects[1].initShaderData(QuadData, QuadIndices, 20, 6);
	//PhObjects[2].initShaderData(TriangleData, vec3(1.0f, 1.0f, 1.0f), 8);

	camera->FocusOnTheObject(&(plane->GetBody()));
*/

}

void FirstLevel::UpDate(float delta_time, const bool *keys, const float angle)
{
/*
	camera->MoveCamera(delta_time);
	plane->Fly(delta_time, keys[W], keys[S], angle);	

	PhObjects[0].AttractAndMove(delta_time);
	PhObjects[1].AttractAndMove(delta_time);
	PhObjects[2].AttractAndMove(delta_time);
*/
}

/*
void RenderAABB(const GraphObject& object)
{
	Shader& shader = object.GetShader();
	Texture2D& texture = object.GetTexture();
	shader.Use();
	glActiveTexture(GL_TEXTURE0);
	texture.Bind();
	shader.SetVector3("First", vec3(-1.0, -1.0, 0.0));
	shader.SetVector3("Second", vec3(-1.0, -1.0, 0.0));
	object.DrawContour(*camera, 4);
}
*/

void FirstLevel::Render()
{
//	RenderAABB(GrObjects[1]);
	glm::vec2 AABB[2] = {
		glm::vec2(-1.0, -1.0),
		glm::vec2(1.0, 1.0),
	};
	//GrObjects[1].Draw(*camera);
    Collis.Draw(*camera, vec3(0.0, 0.0, 0.0), 0.0);
    Collis.DrawAABB(*camera, AABB);
/*
	GrObjects[0].Draw(*camera);
	plane->Render(*camera);
	PhObjects[0].Draw(*camera);
	PhObjects[1].Draw(*camera);
*/
//	PhObjects[2].DrawContour(*camera, 20);

}

FirstLevel::FirstLevel() {}

FirstLevel::~FirstLevel()
{
	camera->CancelFocus();
	delete plane;
}
