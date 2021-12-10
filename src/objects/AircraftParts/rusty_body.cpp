#include "rusty_body.h"

Aircraft::RustyBody::RustyBody() :
		Body(
		  RUST_BODY, 1000
        ,  "../resources/collisions/rusty_body.collis"
        , 2000, 700
        , ResourceManager::Instance().GetShader("plane")
        , ResourceManager::Instance().LoadTexture("body"
        , "../resources/aircraft_parts/rusty_body.png")
		, glm::vec3(0.0, 0.0, 0.0), glm::vec3(2.236, 1.0, 1.0)
        , glm::vec3(0.0, 0.0, 0.0)
		)
{
	StartEnginesPos[RUST_ENGINE] = glm::vec3(1.66*1.9, -0.075, 0.0);
	StartWingsPos[RUST_WINGS] = glm::vec3(1.55*0.5, -0.58, 0.0);
	StartTailsPos[RUST_TAIL] = glm::vec3(2*-1.5, 0.468, 0.0);
}
