#version 430

layout (location = 0) in vec3 Position;
layout (location = 1) in vec2 TexPosition;

uniform mat4 CameraMatrix;
uniform mat4 ModelMatrix;

out vec2 TexCoord;

void main()
{
	gl_Position = CameraMatrix * ModelMatrix * vec4(Position, 1.0f);
	TexCoord = TexPosition;
}




