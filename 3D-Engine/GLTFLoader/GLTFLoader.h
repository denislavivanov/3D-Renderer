#pragma once

#include <vector>
#include "../Mesh.h"

class GLTFLoader
{
public:
	static void Load(const std::string& path, std::vector<Mesh>& meshes);

private:
	static void LoadBuffer(const std::string& path, std::vector<unsigned char>& buffer);
};

