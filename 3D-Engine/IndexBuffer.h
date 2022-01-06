#pragma once

#include <GL/glew.h>


class IndexBuffer
{
public:
	IndexBuffer(unsigned int* indices, unsigned int size);

	~IndexBuffer();

	void Bind() const;

	void Unbind() const;

private:
	GLuint m_BufferID;
};

