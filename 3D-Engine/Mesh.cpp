#include "Mesh.h"


Mesh::Mesh()
	: m_DataCount(0),
	  m_IndexCount(0),
	  m_TextureOffset(0),
	  indices(nullptr),
	  vertices(nullptr)
{
}

Mesh::Mesh(std::vector<float>& vertices, std::vector<unsigned>& indices)
	: m_DataCount(vertices.size()),
	  m_IndexCount(indices.size()),
	  m_TextureOffset(0)
{
	this->vertices = new float[m_DataCount];
	this->indices = new unsigned[m_IndexCount];

	std::copy(vertices.begin(), vertices.end(), this->vertices);
	std::copy(indices.begin(), indices.end(), this->indices);
}

void Mesh::Draw(Shader& shader)
{
	shader.Bind();
	m_VAO.Bind();

	glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_INT, nullptr);
}

void Mesh::Load()
{
	m_VAO.Bind();

	m_VBO.Load(vertices, m_DataCount);
	m_EBO.Load(indices, m_IndexCount);

	m_VAO.SetVertexBuffer(&m_VBO);
	m_VAO.SetIndexBuffer(&m_EBO);

	m_VBO.SetLayout(0, 3, 0, 0);
	m_VBO.SetLayout(1, 2, 0, m_TextureOffset);
}

void Mesh::Free()
{
	delete[] vertices;
	delete[] indices;
}

void Mesh::Destroy()
{
	m_VAO.Destroy();
	m_VBO.Destroy();
	m_EBO.Destroy();
	m_Texture.Destroy();
}

void Mesh::LoadTexture(const std::string& path)
{
	m_Texture.Bind();
	m_Texture.Load(path);
}

void Mesh::SetIndexCount(int count)
{
	m_IndexCount = count;
}

void Mesh::SetTextureOffset(int offset)
{
	m_TextureOffset = offset;
}

void Mesh::SetFlipTexture(bool enabled)
{
	m_Texture.SetFlipped(enabled);
}

void Mesh::SetDataCount(int count)
{
	m_DataCount = count;
}
