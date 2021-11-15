#include "rusty_tail.h"

RustyTail::RustyTail(const Shader& shader) :
			Tail(
				RUST_TAIL, 1, 0, 200, 100, shader,
				resources.LoadTexture("tail", "../resources/Tails/Rusty_tail.png"),
				vec3(0.0, 0.0, 0.0), vec3(1.05*0.7979, 1.05*1, 1), vec3(0.0, 0.0, 0.0)
				) {}

void RustyTail::GetShapes(Shape** planeShapes, unsigned int& pos)
{
	unsigned int firstNumPoints = 4;
	glm::vec2 firstPoints[firstNumPoints] = { 
		glm::vec2(-1.0, -1.0), glm::vec2(-1.0, 1.0),
		glm::vec2(1.0, 1.0), glm::vec2(1.0, -1.0) 
	};

	mat4 ScaleMat = glm::scale(glm::mat4(1.0f), vec3(1.05*0.7979, 1.05*1.0, 1.0));
	for(unsigned int i = 0; i < firstNumPoints; i++) {
		firstPoints[i] = glm::vec2(ScaleMat * glm::vec4(firstPoints[i], 0.0, 0.0));
	}

	planeShapes[pos] = new Shape(firstPoints, glm::vec2(0.0, 0.0), firstNumPoints);
	pos++;
}
