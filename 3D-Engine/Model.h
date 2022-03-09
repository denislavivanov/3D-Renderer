#pragma once
#include "Mesh.h"
#include <vector>


class Model
{
public:
	Model();
	Model(const std::string& path);
	
	void Load(const std::string& path);
	void Draw(Shader& shader);

private:
	std::vector<Mesh> m_Meshes;
};

