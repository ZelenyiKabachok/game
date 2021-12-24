#version 330

layout (lines) in;
layout (line_strip, max_vertices = 5) out;

uniform vec3 v3First;
uniform vec3 v3Second;
uniform mat4 matPosition;
uniform mat4 matCamera;

void Emit(vec4 v4Point)
{
    gl_Position = v4Point;
    EmitVertex();
}

void main()
{

    vec4 v4First = matCamera * matPosition * vec4(v3First, 1.0f);
    vec4 v4Second = matCamera * matPosition * vec4(v3Second, 1.0f);

    vec4 v4Bottom = v4First;
    v4Bottom.x = v4Second.x;

    vec4 v4Up = v4First;
    v4Up.y = v4Second.y;

    Emit(v4First);
    Emit(v4Bottom);
    Emit(v4Second);
    Emit(v4Up);
    Emit(v4First);

    EndPrimitive();
}

