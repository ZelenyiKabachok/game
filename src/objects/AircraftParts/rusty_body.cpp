#include "rusty_body.h"

RustyBody::RustyBody(const Shader& shader) :
		Body(
			RUST_BODY, 1000.0, 2000, 700, shader,
			resources.LoadTexture("body", "../resources/Bodies/Rusty_body.png"),
			vec3(0.0, 0.0, 0.0), vec3(2.236, 1.0, 1.0), vec3(0.0, 0.0, 0.0)
		)
{
	StartEnginesPos[RUST_ENGINE] = vec3(1.66*1.9, -0.075, 0.0);
	StartWingsPos[RUST_WINGS] = vec3(1.55*0.5, -0.58, 0.0);
	StartTailsPos[RUST_TAIL] = vec3(2*-1.5, 0.468, 0.0);
}

