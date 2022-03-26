#pragma once

#include <iostream>
#include <GL/glew.h>

#include "stb/stb_image.h"

class Texture
{
public:
	Texture();
	Texture(const std::string& path, bool flipped);
	~Texture();

	void Load(const std::string& path);
	void Destroy();

	void SetFlipped(bool enabled);

	unsigned int GetWidth() const;
	unsigned int GetHeight() const;

	void Bind() const;
	void Unbind() const;

private:
	bool m_Flipped;

	int m_Width;
	int m_Height;
	int m_Channels;

	GLuint m_TextureID;
};

