#include "rusty_engine.h"

RustyEngine::RustyEngine(Shader& shader) :
		Engine(
			RustEngine, 20000, vec3(15000, 0.0, 0.0),
			vec3(100, 0.0, 0.0), 100, 4, 1000, 400, shader,
			resources.LoadTexture("engine", "../resources/Engines/Rusty_engine.png"),
			vec3(0.0, 0.0, 0.0), vec3(0.59*1.568, 0.59*1.0, 1.0), vec3(0.0, 0.0, 0.0)
		) {}

