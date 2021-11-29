#include "rusty_body.h"

Aircraft::RustyBody::RustyBody(const Graphic::Shader& shader) :
		Body(
		  RUST_BODY, 1, 1000.0, 2000, 700, shader
		, resources.LoadTexture("body", "../resources/Bodies/Rusty_body.png")
		, glm::vec3(0.0, 0.0, 0.0), glm::vec3(2.236, 1.0, 1.0)
        , glm::vec3(0.0, 0.0, 0.0)
		)
{
	StartEnginesPos[RUST_ENGINE] = glm::vec3(1.66*1.9, -0.075, 0.0);
	StartWingsPos[RUST_WINGS] = glm::vec3(1.55*0.5, -0.58, 0.0);
	StartTailsPos[RUST_TAIL] = glm::vec3(2*-1.5, 0.468, 0.0);
}

void Aircraft::RustyBody::GetShapes(Physic::Shape** ppPlaneShapes
                                              , unsigned int& pos)
{
	unsigned int firstNumPoints = 4;
	glm::vec2 firstPoints[firstNumPoints] = { 
		glm::vec2(-1.0, -1.0), glm::vec2(-1.0, 1.0),
		glm::vec2(1.0, 1.0), glm::vec2(1.0, -1.0) 
	};

	glm::mat4 matScale = glm::scale(glm::mat4(1.0f)
                                    , glm::vec3(2.236*1.0, 1.0, 1.0));
	for(unsigned int i = 0; i < firstNumPoints; i++) {
		firstPoints[i] = glm::vec2(matScale * glm::vec4(firstPoints[i], 0.0, 0.0));
	}

	ppPlaneShapes[pos] = new Physic::Shape(firstPoints, glm::vec2(0.0, 0.0)
                                                          , firstNumPoints);
	pos++;
}
