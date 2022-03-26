#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aTexCoords;

out vec2 vTexCoords;

uniform mat4 view;
uniform mat4 projection;

void main()
{
	vTexCoords = aTexCoords;

	gl_Position = projection * view * vec4(-0.5f * aPos, 1.0f);
}