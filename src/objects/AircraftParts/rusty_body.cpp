#include "rusty_body.h"

RustyBody::RustyBody(Shader& shader) :
		Body(
			RustBody, 1000.0, 2000, 700, shader,
			resources.LoadTexture("body", "../resources/Bodies/Rusty_body.png"),
			vec3(0.0, 0.0, 0.0), vec3(2.236, 1.0, 1.0), vec3(0.0, 0.0, 0.0)
		)
{
	StartEnginesPos[RustEngine] = vec3(1.4945*1.9, -0.0665, 1.0);
	StartWingsPos[RustWings] = vec3(1.55*0.5, -0.58, 0.0);
	StartTailsPos[RustTail] = vec3(2*-1.5, 0.468, 0.0);
}

