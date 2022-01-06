#include "VertexArray.h"

VertexArray::VertexArray()
{
	glCreateVertexArrays(1, &m_VertexArrayID);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &m_VertexArrayID);
}

void VertexArray::Bind() const
{
	glBindVertexArray(m_VertexArrayID);
}

void VertexArray::Unbind() const
{
	glBindVertexArray(0);
}

void VertexArray::SetVertexBuffer(VertexBuffer* buffer)
{
	glBindVertexArray(m_VertexArrayID);
	
	buffer->Bind();

	m_VertexBuffers.push_back(buffer);
}

void VertexArray::SetIndexBuffer(IndexBuffer* buffer)
{
	glBindVertexArray(m_VertexArrayID);
	
	buffer->Bind();

	m_IndexBuffer = buffer;
}
