#version 330 core

//in vec2 v_texCoord;
in vec4 v_color;

out vec4 color;


void main()
{
    color = v_color; 
    //color = v_color * u_Color * intensity;
};