#include "rusty_body.h"

RustyBody::RustyBody() :
		Body(
			RustBody, 1000.0, 3000, 800, 
			resources.GetShader("plane"),
			resources.LoadTexture("body", "../resources/Bodies/Rusty_body.png"),
			vec3(0.0, 0.0, 0.0), vec3(2 * 2.236, 2 * 1.0, 1.0), vec3(0.0, 0.0, 0.0)
		)
{
	StartEnginesPos[RustEngine] = vec3(0.0, 0.0, 0.0);
	StartWingsPos[RustWings] = vec3(0.0, 0.0, 0.0);
	StartTailsPos[RustTail] = vec3(0.0, 0.0, 0.0);
}
