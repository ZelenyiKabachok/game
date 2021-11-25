#version 330

uniform vec3 Position;
uniform mat4 CameraMatrix;
uniform mat4 ModelMatrix;

void main()
{
	gl_Position = CameraMatrix * ModelMatrix * vec4(Position, 1.0f);
}
