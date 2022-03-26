#pragma once

#include <vector>
#include <GL/glew.h>
#include "VertexBuffer.h"
#include "IndexBuffer.h"

class VertexArray
{
public:
	VertexArray();
	~VertexArray();

	void Bind() const;
	void Unbind() const;

	void SetVertexBuffer(VertexBuffer* buffer);
	void SetIndexBuffer(IndexBuffer* buffer);

	void Destroy();

private:
	GLuint m_VertexArrayID;
};

