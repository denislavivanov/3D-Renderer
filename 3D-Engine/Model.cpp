#include <string>
#include "Model.h"
#include "GLTFLoader/GLTFLoader.h"

Model::Model()
{
}

Model::Model(const std::string& path)
{
	GLTFLoader::Load(path, m_Meshes);
}

void Model::Load(const std::string& path)
{
	GLTFLoader::Load(path, m_Meshes);
}

void Model::Draw(Shader& shader)
{
	for (Mesh& mesh : m_Meshes)
	{
		mesh.Draw(shader);
	}
}
