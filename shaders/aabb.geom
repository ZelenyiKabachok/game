#version 330

layout (lines) in;
layout (line_strip, max_vertices = 5) out;

uniform vec3 First;
uniform vec3 Second;
uniform mat4 Camera;

void main()
{

	vec4 first = Camera * vec4(First, 1.0f);
	vec4 second = Camera * vec4(Second, 1.0f);

	vec4 tmp = first;
	tmp.x = second.x;

	gl_Position = first;
	EmitVertex();

	gl_Position = tmp;
	EmitVertex();

	gl_Position = second;
	EmitVertex();

	tmp = first;
	tmp.y = second.y;

	gl_Position = tmp;
	EmitVertex();

    gl_Position = first;
    EmitVertex();
/*
    gl_Position = Camera*gl_in[0].gl_Position;
    EmitVertex();
    
    gl_Position = Camera*gl_in[1].gl_Position;
    EmitVertex();

    gl_Position = Camera*(gl_in[0].gl_Position + vec4(2.0, 0.0, 0.0, 0.0));
    EmitVertex();
*/

	EndPrimitive();
}






