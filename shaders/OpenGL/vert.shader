#version 330 core

layout (location = 0) in vec3 position;

out vec3 v_Position;

uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

void main()
{
	v_Position = position * 0.5f + 0.5f;
	gl_Position = projectionMatrix * viewMatrix * vec4(position, 1.0f);
}