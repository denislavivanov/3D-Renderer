#pragma once

#include <vector>
#include "../Mesh.h"

class GLTFLoader
{
public:
	static void Load(const std::string& path, std::vector<Mesh>& meshes);

private:
	static bool LoadBuffer(const std::string& path, std::vector<unsigned char>& buffer);
};

