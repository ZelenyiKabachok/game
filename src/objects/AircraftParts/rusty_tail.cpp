#include "rusty_tail.h"

Aircraft::RustyTail::RustyTail(const Graphic::Shader& shader) :
			Tail(
			  RUST_TAIL, 1, 200, 100, shader
			, resources.LoadTexture("tail", "../resources/Tails/Rusty_tail.png")
			, glm::vec3(0.0, 0.0, 0.0), glm::vec3(1.05*0.7979, 1.05*1, 1)
            , glm::vec3(0.0, 0.0, 0.0)
				) {}

void Aircraft::RustyTail::GetShapes(Physic::Shape** ppPlaneShapes, unsigned int& pos)
{
	unsigned int firstNumPoints = 4;
	glm::vec2 firstPoints[firstNumPoints] = { 
		glm::vec2(-1.0, -1.0), glm::vec2(-1.0, 1.0),
		glm::vec2(1.0, 1.0), glm::vec2(1.0, -1.0) 
	};

	glm::mat4 matScale = glm::scale(glm::mat4(1.0f)
                       , glm::vec3(1.05*0.7979, 1.05*1.0, 1.0));
	for(unsigned int i = 0; i < firstNumPoints; i++) {
		firstPoints[i] = glm::vec2(matScale * glm::vec4(firstPoints[i], 0.0, 0.0));
	}

	ppPlaneShapes[pos] = new Physic::Shape(firstPoints, glm::vec2(0.0, 0.0)
                                                        , firstNumPoints);
	pos++;
}
