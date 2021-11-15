#include "rusty_wings.h"

RustyWings::RustyWings(const Shader& shader) :
			Wings(
				RUST_WINGS, 1, 600, 620, 500, 200, shader,
				resources.LoadTexture("wings", "../resources/Wings/Rusty_wings.png"),
				vec3(0.0, 0.0, 0.0), vec3(0.4*2.736, 0.4*1.0, 1.0), vec3(0.0, 0.0, 0.0)
			) {}

void RustyWings::GetShapes(Shape** const planeShapes, unsigned int& pos)
{
	unsigned int firstNumPoints = 4;
	glm::vec2 firstPoints[firstNumPoints] = { 
		glm::vec2(-1.0, -1.0), glm::vec2(-1.0, 1.0),
		glm::vec2(1.0, 1.0), glm::vec2(1.0, -1.0) 
	};

	mat4 ScaleMat = glm::scale(glm::mat4(1.0f), vec3(0.4*2.736, 0.4*1.0, 1.0));
	for(unsigned int i = 0; i < firstNumPoints; i++) {
		firstPoints[i] = glm::vec2(ScaleMat * glm::vec4(firstPoints[i], 0.0, 0.0));
	}

	planeShapes[pos] = new Shape(firstPoints, glm::vec2(0.0, 0.0), firstNumPoints);
	pos++;
}
