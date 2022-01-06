#version 330

layout (location = 0) in vec3 v3Position;

uniform mat4 matProjection;
uniform mat4 matPosition;
uniform mat4 matRotation;
uniform mat4 matScale;

void main()
{
	gl_Position = matProjection * matPosition * matRotation * matScale
                              * vec4(v3Position, 1.0f);
}

