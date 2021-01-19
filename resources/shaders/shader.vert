#version 450 core

layout(location = 0) in vec2 a_position;
layout(location = 1) in vec3 a_color;

uniform mat4 u_projection;

out V2F
{
    vec3 color;
} v2f;

void main()
{
    gl_Position = u_projection * vec4(a_position, 0, 1);

    v2f.color = a_color;
}