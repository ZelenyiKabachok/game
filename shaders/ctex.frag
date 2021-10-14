#version 430

in vec3 Color;
in vec2 TexCoord;

out vec4 FragColor;

uniform sampler2D ourTexture1;
uniform sampler2D ourTexture2;

void main()
{
	FragColor = mix(texture(ourTexture1, TexCoord), texture(ourTexture2, TexCoord), 0.5);
}
