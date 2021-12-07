#include "rusty_wings.h"

Aircraft::RustyWings::RustyWings(Graphic::Shader& shader) :
			Wings(
			RUST_WINGS, 600, 620
            , "../resources/collisions/rusty_wings.collis"
            , 500, 200, shader
			, ResourceManager::Instance().LoadTexture("wings"
            , "../resources/aircraft_parts/rusty_wings.png")
			, glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.4*2.736, 0.4*1.0, 1.0)
            , glm::vec3(0.0, 0.0, 0.0)
			) {}
