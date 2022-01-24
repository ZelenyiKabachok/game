#version 330

in vec3 v3FragColor;

out vec4 FragColor;

void main()
{
    FragColor = vec4(v3FragColor, 1.0);
}
