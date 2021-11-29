#include "rusty_wings.h"

Aircraft::RustyWings::RustyWings(const Graphic::Shader& shader) :
			Wings(
			RUST_WINGS, 1, 600, 620, 500, 200, shader
			, resources.LoadTexture("wings", "../resources/Wings/Rusty_wings.png")
			, glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.4*2.736, 0.4*1.0, 1.0)
            , glm::vec3(0.0, 0.0, 0.0)
			) {}

void Aircraft::RustyWings::GetShapes(Physic::Shape** ppPlaneShapes
                                                , unsigned int& pos)
{
	unsigned int firstNumPoints = 4;
	glm::vec2 firstPoints[firstNumPoints] = { 
		glm::vec2(-1.0, -1.0), glm::vec2(-1.0, 1.0),
		glm::vec2(1.0, 1.0), glm::vec2(1.0, -1.0) 
	};

	glm::mat4 matScale = glm::scale(glm::mat4(1.0f)
                                  , glm::vec3(0.4*2.736, 0.4*1.0, 1.0));
	for(unsigned int i = 0; i < firstNumPoints; i++) {
		firstPoints[i] = glm::vec2(matScale * glm::vec4(firstPoints[i]
                                                          , 0.0, 0.0));
	}

	ppPlaneShapes[pos] = new Physic::Shape(firstPoints, glm::vec2(0.0, 0.0)
                                                          , firstNumPoints);
	pos++;
}
