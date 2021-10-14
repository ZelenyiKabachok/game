#version 330

layout (location = 0) in vec3 VertexPosition;
layout (location = 1) in vec3 VertexColor;

uniform mat4 RotationMatrix;

out vec3 Color;

void main()
{
	gl_Position = RotationMatrix * vec4(VertexPosition, 1.0);
	Color = VertexColor;
}

