#include "rusty_engine.h"

RustyEngine::RustyEngine(const Shader& shader) :
		Engine(
			RUST_ENGINE, 1, 20000, vec3(15000, 0.0, 0.0),
			vec3(500, 0.0, 0.0), 500, 4, 1000, 400, shader,
			resources.LoadTexture("engine", "../resources/Engines/Rusty_engine.png"),
			vec3(0.0, 0.0, 0.0), vec3(0.59*1.568, 0.59*1.0, 1.0), vec3(0.0, 0.0, 0.0)
		) {}

void RustyEngine::GetShapes(Shape** const planeShapes, unsigned int& pos)
{
	unsigned int firstNumPoints = 4;
	glm::vec2 firstPoints[firstNumPoints] = { 
		glm::vec2(-1.0, -1.0), glm::vec2(-1.0, 1.0),
		glm::vec2(1.0, 1.0), glm::vec2(1.0, -1.0) 
	};

	mat4 ScaleMat = glm::scale(glm::mat4(1.0f), vec3(0.59*1.568, 0.59*1.0, 1.0));
	for(unsigned int i = 0; i < firstNumPoints; i++) {
		firstPoints[i] = glm::vec2(ScaleMat * glm::vec4(firstPoints[i], 0.0, 0.0));
	}

	planeShapes[pos] = new Shape(firstPoints, glm::vec2(0.0, 0.0), firstNumPoints);
	pos++;
}
