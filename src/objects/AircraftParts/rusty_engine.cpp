#include "rusty_engine.h"

Aircraft::RustyEngine::RustyEngine(Graphic::Shader& shader) :
		Engine(
		  RUST_ENGINE, "../resources/collisions/rusty_engine.collis"
        , 20000, glm::vec3(15000, 0.0, 0.0)
		, glm::vec3(500, 0.0, 0.0), 500, 4, 1000, 400, shader
		, ResourceManager::Instance().LoadTexture("engine"
        , "../resources/aircraft_parts/rusty_engine.png")
		, glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.59*1.568, 0.59*1.0, 1.0)
        , glm::vec3(0.0, 0.0, 0.0)) {}
