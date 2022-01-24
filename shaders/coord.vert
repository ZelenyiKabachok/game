#version 330

layout (location = 0) in vec3 v3Position;
layout (location = 1) in vec3 v3Color;

uniform mat4 matCamera;

out vec3 v3FragColor;

void main()
{
    v3FragColor = v3Color;
    gl_Position = matCamera * vec4(v3Position, 1.0f); 
}
