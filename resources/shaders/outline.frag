#version 450 core

in V2F
{
    vec4 color;
} v2f;

uniform float u_time;

out vec4 o_color;

void main()
{
    float l = step(0.5f, mod(u_time,1.0f));
    o_color = vec4(v2f.color.x*l,v2f.color.y*l,v2f.color.z*l, 1.0);
}