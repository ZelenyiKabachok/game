#include "rusty_tail.h"

RustyTail::RustyTail(const Shader& shader) :
			Tail(
				RustTail, 0, 200, 100, shader,
				resources.LoadTexture("tail", "../resources/Tails/Rusty_tail.png"),
				vec3(0.0, 0.0, 0.0), vec3(1.05*0.7979, 1.05*1, 1), vec3(0.0, 0.0, 0.0)
			) {}

