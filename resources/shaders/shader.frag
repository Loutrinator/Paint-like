#version 450 core

in V2F
{
    vec4 color;
} v2f;

out vec4 o_color;

void main()
{
    o_color = v2f.color;
}