#version 330

layout (lines) in;
layout (line_strip, max_vertices = 4) out;

uniform vec3 First;
uniform vec3 Second;

void main()
{
	vec4 first = vec4(First, 1.0f);
	vec4 second = vec4(Second, 1.0f);
	vec4 tmp = first;
	tmp.x = second.x;

	gl_Position = first;
	EmitVertex();
	gl_Position = tmp;
	EmitVertex();
	gl_Position = second;
	EmitVertex();

	tmp = first;
	tmp.x = second.x;

	gl_Position = tmp;
	EmitVertex();

	EndPrimitive();
}

