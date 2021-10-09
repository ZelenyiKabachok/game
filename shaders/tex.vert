#version 430

layout (location = 0) in vec3 positionData;
layout (location = 1) in vec3 colorData;
layout (location = 2) in vec2 texData;

out vec3 Color;
out vec2 TexCoord;

void main()
{
	gl_Position = vec4(positionData, 1.0);
	Color = colorData;
	TexCoord = texData;
}




