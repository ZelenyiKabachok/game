#version 330

layout (location = 0) in vec4 vertex;
out vec2 TexCoords;

uniform mat4 matProjection;

void main()
{
    gl_Position = matProjection * vec4(vertex.xy, 0.0, 1.0);
    TexCoords = vertex.zw;
}

