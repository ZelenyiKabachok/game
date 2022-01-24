#include "rusty_tail.h"

Aircraft::RustyTail::RustyTail() :
			Tail(
			  RUST_TAIL, "../resources/collisions/rusty_tail.collis"
            , 200, 100
            , ResourceManager::Instance().GetShader("graphic")
			, ResourceManager::Instance().LoadTexture("tail"
            , "../resources/aircraft_parts/rusty_tail.png")
			, glm::vec3(0.0, 0.0, 0.0), glm::vec3(1.05*0.7979, 1.05*1, 1)
            , glm::vec3(0.0, 0.0, 0.0)
				) {}
