#pragma once
#include "Mesh.h"
#include "Texture.h"


class Model
{
public:
	void Load(std::string path);


private:
	Mesh mesh;
	Texture texture;
};

