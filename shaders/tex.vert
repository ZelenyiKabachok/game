#version 430

layout (location = 0) in vec3 Position;
layout (location = 1) in vec3 Color;
layout (location = 2) in vec2 TexPosition;

out vec3 DataColor;
out vec2 TexCoord;

uniform mat4 CameraMatrix;

void main()
{
	gl_Position = CameraMatrix * vec4(Position, 1.0f);
	DataColor = Color;
	TexCoord = TexPosition;
}


