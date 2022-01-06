#include <string>
#include "Model.h"

void Model::Load(std::string path)
{
	FILE* fp = fopen((path + "/scene.bin").c_str(), "rb");

	fclose(fp);
}
