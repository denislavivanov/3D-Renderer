#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include <GL/glew.h>

class VertexBuffer
{
public:
	VertexBuffer();
	VertexBuffer(float* vertices, unsigned int size);

	~VertexBuffer();

	void Destroy();
	void Load(float* vertices, unsigned int size);

	void Bind() const;
	void Unbind() const;

	void SetLayout(GLuint Location, int Count, int Stride, int Offset);

private:
	GLuint m_BufferID;
};

#endif
