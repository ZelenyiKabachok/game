#include "coll_draw.h"

//extern ResourceManager resources;

void Graphic::CollDraw::Init(Physic::Shape **ppShapes
                    , unsigned int numOfShapes, const glm::vec2 *pV2AABB)
{
    Graphic::Shader& shader = ResourceManager::Instance().GetShader("plane");
    Graphic::Shader& aabb = ResourceManager::Instance().GetShader("aabb");
    Graphic::Texture2D& texture = ResourceManager::Instance().GetTexture("collis");

	number = numOfShapes;
	ppGraphic = new ShapeDraw*[numOfShapes+1];
	for(unsigned int i = 0; i < numOfShapes; i++) {
		ppGraphic[i] = new ShapeDraw(shader, texture, glm::vec3(0.0, 0.0, 0.0));
	}
	ppGraphic[numOfShapes] = new ShapeDraw(aabb, texture, glm::vec3(0.0));

	for(unsigned int i = 0; i < numOfShapes; i++) {
		ppGraphic[i]->initShaderData(ppShapes[i]->pV2Points
                                    , glm::vec3(0.0, 0.0, 1.0)
									, ppShapes[i]->num_points);
	}
	ppGraphic[numOfShapes]->initShaderData(pV2AABB, glm::vec3(1.0, 0.0, 0.0)
                                           , 2, GL_LINE_STRIP);
}

void Graphic::CollDraw::DrawAABB(const Camera& camera
                                , const glm::vec2 *pV2AABB
                                , const glm::vec3& v3Pos) const
{
    const Shader &shader = ppGraphic[number]->GetShader(); 
    const Texture2D &texture = ppGraphic[number]->GetTexture();
	shader.Use();

	glActiveTexture(GL_TEXTURE0);
	texture.Bind();

    glm::mat4 matPos = translate(glm::mat4(1.0f), v3Pos);

	shader.SetMatrix4("matCamera", camera.GetMatrix());
    shader.SetMatrix4("matPosition", matPos);
    shader.SetVector3("v3First", glm::vec3(pV2AABB[0], 0.0));
    shader.SetVector3("v3Second", glm::vec3(pV2AABB[1], 0.0));
	shader.SetVector3("v3Color", ppGraphic[number]->v3Color);
	
	glBindVertexArray(ppGraphic[number]->VAO);
	glLineWidth(1.25);
	glDrawArrays(ppGraphic[number]->type, 0, ppGraphic[number]->points);
}

void Graphic::CollDraw::Draw(const Camera& camera
                           , const glm::vec3& v3Pos, float angle) const
{
//    printf("Ok, %u\n", number);
	for(unsigned int i = 0; i < number; i++) {
		ppGraphic[i]->ChangePosition(v3Pos);
		ppGraphic[i]->ChangeSlantAngle(angle);
	}

	for(unsigned int i = 0; i < number; i++) {
		ppGraphic[i]->Draw(camera, 1.25);
	}
}
		
Graphic::CollDraw::~CollDraw()
{
    if(ppGraphic) {
	    for(unsigned int i = 0; i <= number; i++) {
		    delete ppGraphic[i];
	    }
	    delete ppGraphic;
    }
}
