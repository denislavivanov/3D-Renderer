#pragma once
#include <iostream>
#include <GL/glew.h>

#include "stb_image.h"

class Texture
{
public:
	Texture(const std::string& path);
	~Texture();

	unsigned int GetWidth() const;
	unsigned int GetHeight() const;

	void Bind() const;
	void Unbind() const;

private:
	int m_Width;
	int m_Height;
	int m_Channels;
	GLuint m_TextureID;
};

