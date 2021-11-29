#include "rusty_engine.h"

Aircraft::RustyEngine::RustyEngine(const Graphic::Shader& shader) :
		Engine(
		  RUST_ENGINE, 1, 20000, glm::vec3(15000, 0.0, 0.0)
		, glm::vec3(500, 0.0, 0.0), 500, 4, 1000, 400, shader
		, resources.LoadTexture("engine", "../resources/Engines/Rusty_engine.png")
		, glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.59*1.568, 0.59*1.0, 1.0)
        , glm::vec3(0.0, 0.0, 0.0)) {}

void Aircraft::RustyEngine::GetShapes(Physic::Shape** ppPlaneShapes
                                                , unsigned int& pos)
{
	unsigned int firstNumPoints = 4;
	glm::vec2 firstPoints[firstNumPoints] = { 
		glm::vec2(-1.0, -1.0), glm::vec2(-1.0, 1.0),
		glm::vec2(1.0, 1.0), glm::vec2(1.0, -1.0) 
	};

	glm::mat4 matScale = glm::scale(glm::mat4(1.0f)
                        , glm::vec3(0.59*1.568, 0.59*1.0, 1.0));
	for(unsigned int i = 0; i < firstNumPoints; i++) {
		firstPoints[i] = glm::vec2(matScale * glm::vec4(firstPoints[i], 0.0, 0.0));
	}

	ppPlaneShapes[pos] = new Physic::Shape(firstPoints, glm::vec2(0.0, 0.0)
                                                        , firstNumPoints);
	pos++;
}
