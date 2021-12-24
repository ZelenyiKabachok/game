#version 330

layout (location = 0) in vec3 Position;
layout (location = 1) in vec2 TexPosition;

uniform mat4 matCamera;
uniform mat4 matPosition;
uniform mat4 matRotation;
uniform mat4 matScale;

out vec2 TexCoord;

void main()
{
	gl_Position = matCamera * matPosition * matRotation
                            * matScale * vec4(Position, 1.0f);
	TexCoord = TexPosition;
}

