#include "coll_draw.h"

void CollDraw::Init(Shape **ppShapes, unsigned int numOfShapes,
											 const glm::vec2 *pAABB)
{
	number = numOfShapes;
	const Shader& shader =	resources.LoadShader("plane", "../shaders/sprite.vert", 
								  "../shaders/sprite.frag");
	const Shader& aabbShader = resources.LoadShader("aabb", "../shaders/sprite.vert",
								"../shaders/sprite.frag", "../shaders/aabb.geom");
	const Texture2D texture = resources.LoadTexture("collis", 
								  "../resources/Others/collis.jpg");
	glm::vec2 AABB[] = {
		glm::vec2(pAABB[0]),
		//glm::vec2(pAABB[0].x, pAABB[1].y),
		glm::vec2(pAABB[1]),
		//glm::vec2(pAABB[1].x, pAABB[0].y),
	};
	ppGraphic = new ShapeDraw*[numOfShapes+1];
	for(unsigned int i = 0; i < numOfShapes; i++) {
		ppGraphic[i] = new ShapeDraw(shader, texture, vec3(0.0, 0.0, 0.0));
	}
	ppGraphic[numOfShapes] = new ShapeDraw(aabbShader, texture, vec3(0.0));

	for(unsigned int i = 0; i < numOfShapes; i++) {
		ppGraphic[i]->initShaderData(ppShapes[i]->pPoints, vec3(0.0, 0.0, 1.0),
									 ppShapes[i]->num_points);
	}
	ppGraphic[numOfShapes]->initShaderData(AABB, glm::vec3(1.0, 0.0, 0.0), 2, GL_LINE_LOOP);
//	ppGraphic[numOfShapes]->
}

void CollDraw::Draw(const Camera& camera, const glm::vec3& pos, float angle)
{
	for(unsigned int i = 0; i < number; i++) {
		ppGraphic[i]->ChangePosition(pos);
		ppGraphic[i]->ChangeSlantAngle(angle);
	}
	//ppGraphic[numOfShapes]->ChangePosition(Position);

	for(unsigned int i = 0; i <= number; i++) {
		ppGraphic[i]->Draw(camera, 2);
	}
}
		
CollDraw::~CollDraw()
{
	for(unsigned int i = 0; i <= number; i++) {
		delete ppGraphic[i];
	}
	delete ppGraphic;
}
