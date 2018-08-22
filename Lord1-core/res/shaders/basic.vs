#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 color;

uniform mat4 u_mvp;

out vec4 v_color;

void main()
{
	gl_Position = u_mvp * position;
	v_color = color;
	//v_color = vec4(1.0, 0, 1.0, 1.0);
}