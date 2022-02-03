#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aTexCoords;

out vec2 vTexCoords;


void main()
{
	vTexCoords = aTexCoords;

    vec4 diff = vec4(0.0f, -0.6f, 0.0f, 0.0f);

	gl_Position = vec4(-0.5f * aPos, 1.0f) + diff;
}