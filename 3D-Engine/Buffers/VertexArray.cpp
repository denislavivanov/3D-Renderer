#include "VertexArray.h"

VertexArray::VertexArray()
{
	glCreateVertexArrays(1, &m_VertexArrayID);
}

VertexArray::~VertexArray()
{
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
}

void VertexArray::SetIndexBuffer(IndexBuffer* buffer)
{
	glBindVertexArray(m_VertexArrayID);
	
	buffer->Bind();
}

void VertexArray::Destroy()
{
	glDeleteVertexArrays(1, &m_VertexArrayID);
}

