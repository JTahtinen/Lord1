#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec4 color;

uniform mat4 u_projection;
uniform mat4 u_view = mat4(1.0);
uniform mat4 u_model = mat4(1.0);

out vec4 v_color;

void main()
{
	gl_Position = u_projection * u_view * u_model * vec4(position.xyz, 1);
	v_color = color;
	//v_color = vec4(1.0, 0, 1.0, 1.0);
}