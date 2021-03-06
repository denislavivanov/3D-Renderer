#include "VertexBuffer.h"
#include <iostream>

VertexBuffer::VertexBuffer() 
{
	glGenBuffers(1, &m_BufferID);
}

VertexBuffer::VertexBuffer(float* vertices, unsigned int size)
{
	glGenBuffers(1, &m_BufferID);
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
	glBufferData(GL_ARRAY_BUFFER, size * sizeof(float), vertices, GL_STATIC_DRAW);
}

void VertexBuffer::Load(float* vertices, unsigned int size)
{
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
	glBufferData(GL_ARRAY_BUFFER, size * sizeof(float), vertices, GL_STATIC_DRAW);
}

void VertexBuffer::Destroy()
{
	glDeleteBuffers(1, &m_BufferID);
}

void VertexBuffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
}

void VertexBuffer::Unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::SetLayout(GLuint Location, int Count, int Stride, int Offset)
{
	glEnableVertexAttribArray(Location);
	glVertexAttribPointer(Location, Count, GL_FLOAT, GL_FALSE, Stride, (const void*)Offset);
}

VertexBuffer::~VertexBuffer()
{
}