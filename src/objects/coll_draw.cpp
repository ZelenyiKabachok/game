#include "coll_draw.h"

void CollDraw::Init(Shape **ppShapes, unsigned int numOfShapes,
											 const glm::vec2 *pAABB)
{
	number = numOfShapes;
	const Shader& shader =	resources.LoadShader("plane", "../shaders/sprite.vert", 
								  "../shaders/sprite.frag");
	const Shader& aabbShader = resources.LoadShader("aabb", "../shaders/aabb.vert",
								"../shaders/aabb.frag", "../shaders/aabb.geom");
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
	ppGraphic[numOfShapes]->initShaderData(AABB, glm::vec3(1.0, 0.0, 0.0), 2, GL_LINE_STRIP);
}

void CollDraw::DrawAABB(const Camera& camera, const glm::vec2 *pAABB)
{
    const Shader &shader = ppGraphic[number]->GetShader(); 
    const Texture2D &texture = ppGraphic[number]->GetTexture();
	shader.Use();

	glActiveTexture(GL_TEXTURE0);
	texture.Bind();
/*
	glm::mat4 ModelMatrix = PositionMatrix * RotateMatrix * SizeMatrix;

	shader.SetMatrix4("CameraMatrix", camera.GetCameraMatrix());
	shader.SetMatrix4("ModelMatrix", ModelMatrix);
*/
	shader.SetMatrix4("Camera", camera.GetCameraMatrix());
	shader.SetVector3("Color", ppGraphic[number]->color);
    shader.SetVector3("First", vec3(pAABB[0], 0.0));
    shader.SetVector3("Second", vec3(pAABB[1], 0.0));
	
	glBindVertexArray(ppGraphic[number]->VAO);
	glLineWidth(9);
	glDrawArrays(ppGraphic[number]->type, 0, ppGraphic[number]->points);
}

void CollDraw::Draw(const Camera& camera, const glm::vec3& pos, float angle)
{
	for(unsigned int i = 0; i < number; i++) {
		ppGraphic[i]->ChangePosition(pos);
		ppGraphic[i]->ChangeSlantAngle(angle);
	}
//	ppGraphic[number]->ChangePosition(pos);

	for(unsigned int i = 0; i < number; i++) {
		ppGraphic[i]->Draw(camera, 9);
	}
}
		
CollDraw::~CollDraw()
{
	for(unsigned int i = 0; i <= number; i++) {
		delete ppGraphic[i];
	}
	delete ppGraphic;
}
