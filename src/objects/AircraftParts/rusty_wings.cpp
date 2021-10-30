#include "rusty_wings.h"

RustyWings::RustyWings(Shader& shader) :
			Wings(
				RustWings, 600, 620, 500, 200, shader,
				resources.LoadTexture("wings", "../resources/Wings/Rusty_wings.png"),
				vec3(0.0, 0.0, 0.0), vec3(0.4*2.736, 0.4*1.0, 1.0), vec3(0.0, 0.0, 0.0)
			) {}

