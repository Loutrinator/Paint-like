#version 450 core

in V2F
{
    vec4 color;
} v2f;

uniform float u_time;

out vec4 o_color;

void main()
{
    float alpha = step(0.5f, mod(u_time,1.0f));
    o_color =vec4(v2f.color.x,v2f.color.y,v2f.color.z, alpha);
}