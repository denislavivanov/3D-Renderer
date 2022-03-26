#version 330 core

in vec2 vTexCoords;
out vec4 aColor;

uniform sampler2D Texture;


void main()
{
	aColor = texture(Texture, vTexCoords);
}