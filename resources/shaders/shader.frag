#version 450 core

in V2F
{
    vec3 color;
} v2f;

out vec4 o_color;

void main()
{
    o_color = vec4(v2f.color, 1);
}