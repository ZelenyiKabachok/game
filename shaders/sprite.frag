#version 330

in vec2 TexCoord;

uniform sampler2D Texture;
uniform vec3 Color;

out vec4 FragColor;

void main()
{
	FragColor = vec4(Color, 1.0f) * texture(Texture, TexCoord);
}
