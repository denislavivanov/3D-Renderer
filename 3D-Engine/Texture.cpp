#include "Texture.h"

Texture::Texture()
	: m_Height(0), 
	  m_Width(0), 
	  m_Channels(0), 
	  m_TextureID(0), 
	  m_Flipped(false)
{
}

Texture::Texture(const std::string& path, bool flipped)
	: m_Flipped(flipped)
{
	Load(path);
}

Texture::~Texture()
{
}

void Texture::Load(const std::string& path)
{
	if (m_Flipped)
	{
		stbi_set_flip_vertically_on_load(true);
	}

	unsigned char* p = stbi_load(path.c_str(), &m_Width, &m_Height, &m_Channels, 0);

	if (!p)
	{
		std::cerr << path + std::string(" failed to load!") << std::endl;
		exit(-1);
	}

	GLenum format = 0;

	switch (m_Channels)
	{
		case 3: format = GL_RGB; break;
		case 4: format = GL_RGBA; break;
		default: std::cerr << "Texture is not supported!" << std::endl;
	}

	glGenTextures(1, &m_TextureID);
	glBindTexture(GL_TEXTURE_2D, m_TextureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, format, m_Width, m_Width, 0, format, GL_UNSIGNED_BYTE, p);

	stbi_image_free(p);
}

void Texture::Destroy()
{
	glDeleteTextures(1, &m_TextureID);
}

void Texture::SetFlipped(bool enabled)
{
	m_Flipped = enabled;
}

unsigned int Texture::GetWidth() const
{
	return m_Width;
}

unsigned int Texture::GetHeight() const
{
	return m_Height;
}

void Texture::Bind() const
{
	glBindTexture(GL_TEXTURE_2D, m_TextureID);
}

void Texture::Unbind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
