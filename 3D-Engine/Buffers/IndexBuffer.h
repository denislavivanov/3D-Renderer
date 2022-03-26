#pragma once

#include <GL/glew.h>


class IndexBuffer
{
public:
	IndexBuffer();
	IndexBuffer(unsigned int* indices, unsigned int size);

	~IndexBuffer();

	void Load(unsigned int* indices, unsigned int size);
	void Destroy();

	void Bind() const;
	void Unbind() const;

private:
	GLuint m_BufferID;
};

