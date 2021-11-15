#include "rusty_body.h"

RustyBody::RustyBody(const Shader& shader) :
		Body(
			RUST_BODY, 1, 1000.0, 2000, 700, shader,
			resources.LoadTexture("body", "../resources/Bodies/Rusty_body.png"),
			vec3(0.0, 0.0, 0.0), vec3(2.236, 1.0, 1.0), vec3(0.0, 0.0, 0.0)
		)
{
	StartEnginesPos[RUST_ENGINE] = vec3(1.66*1.9, -0.075, 0.0);
	StartWingsPos[RUST_WINGS] = vec3(1.55*0.5, -0.58, 0.0);
	StartTailsPos[RUST_TAIL] = vec3(2*-1.5, 0.468, 0.0);
}

void RustyBody::GetShapes(Shape** const planeShapes, unsigned int& pos)
{
	unsigned int firstNumPoints = 4;
	glm::vec2 firstPoints[firstNumPoints] = { 
		glm::vec2(-1.0, -1.0), glm::vec2(-1.0, 1.0),
		glm::vec2(1.0, 1.0), glm::vec2(1.0, -1.0) 
	};

	mat4 ScaleMat = glm::scale(glm::mat4(1.0f), vec3(2.236*1.0, 1.0, 1.0));
	for(unsigned int i = 0; i < firstNumPoints; i++) {
		firstPoints[i] = glm::vec2(ScaleMat * glm::vec4(firstPoints[i], 0.0, 0.0));
	}

	planeShapes[pos] = new Shape(firstPoints, glm::vec2(0.0, 0.0), firstNumPoints);
	pos++;
}
