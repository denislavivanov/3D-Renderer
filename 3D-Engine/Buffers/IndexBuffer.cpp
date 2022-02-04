#include "IndexBuffer.h"


IndexBuffer::IndexBuffer()
{
	glCreateBuffers(1, &m_BufferID);
}

IndexBuffer::IndexBuffer(unsigned int* indices, unsigned int size)
{
	glCreateBuffers(1, &m_BufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

void IndexBuffer::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID);
}

void IndexBuffer::Unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

IndexBuffer::~IndexBuffer()
{
}

void IndexBuffer::Load(unsigned int* indices, unsigned int size)
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(unsigned int), indices, GL_STATIC_DRAW);
}

void IndexBuffer::Destroy()
{
	glDeleteBuffers(1, &m_BufferID);
}
