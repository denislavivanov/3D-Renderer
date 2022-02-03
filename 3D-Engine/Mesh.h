#pragma once
#include "Shader.h"
#include "Buffers/VertexArray.h"
#include "Buffers/VertexBuffer.h"
#include "Buffers/IndexBuffer.h"
#include "Texture.h"


class Mesh
{
public:
	Mesh();
	Mesh(std::vector<float>& vertices, std::vector<unsigned>& indices);

	void Draw(Shader& shader);
	void Load();
	void Free();
	void Destroy();
	void LoadTexture(const std::string& path);
	void SetIndexCount(int count);
	void SetDataCount(int count);
	void SetTextureOffset(int offset);

public:
	float* vertices;
	unsigned* indices;

private:
	int m_IndexCount;
	int m_DataCount;
	int m_TextureOffset;

private:
	VertexArray m_VAO;
	VertexBuffer m_VBO;
	IndexBuffer m_EBO;
	Texture m_Texture;
};

