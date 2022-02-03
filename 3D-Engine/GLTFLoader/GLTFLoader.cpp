#include "GLTFLoader.h"
#include "../json.hpp"
#include <fstream>

using namespace nlohmann;

void GLTFLoader::Load(const std::string& path, std::vector<Mesh>& meshes)
{
	std::vector<unsigned char> buffer;
	std::ifstream file(path + "scene.gltf", std::ios::in);
	json gltf;

	file >> gltf;

	file.close();

	buffer.reserve(gltf["buffers"][0]["byteLength"]);

	LoadBuffer(path + std::string(gltf["buffers"][0]["uri"]), buffer);

	unsigned char* ptr_buffer = buffer.data();

	for (auto& mesh : gltf["meshes"])
	{
		meshes.push_back(Mesh());
		Mesh& current_mesh = meshes.back();

		{
			auto& index_accessor = gltf["accessors"][(int)mesh["primitives"][0]["indices"]];
			auto& index_bufferview = gltf["bufferViews"][(int)index_accessor["bufferView"]];
			int index_accessor_offset = index_accessor.contains("byteOffset") ? (int)index_accessor["byteOffset"] : 0;
			int start = index_bufferview["byteOffset"] + index_accessor_offset;
			int index_count = index_accessor["count"];

			current_mesh.SetIndexCount(index_count);
			current_mesh.indices = new unsigned[index_count];

			if (index_accessor["componentType"] == 5125) //int
			{
				int stride = index_bufferview.contains("byteStride") ? (int)index_bufferview["byteStride"] : 4;

				for (int i = 0; i < index_count; ++i)
				{
					current_mesh.indices[i] = *(unsigned int*)(ptr_buffer + start + i * stride);
				}
			}
			else //short
			{
				int stride = index_bufferview.contains("byteStride") ? (int)index_bufferview["byteStride"] : 2;

				for (int i = 0; i < index_count; ++i)
				{
					current_mesh.indices[i] = *(unsigned short*)(ptr_buffer + start + i * stride);
				}
			}
		}

		{
			auto& vertex_accessor = gltf["accessors"][(int)mesh["primitives"][0]["attributes"]["POSITION"]];
			auto& tex_accessor = gltf["accessors"][(int)mesh["primitives"][0]["attributes"]["TEXCOORD_0"]];
			auto& vertex_bufferview = gltf["bufferViews"][(int)vertex_accessor["bufferView"]];
			auto& tex_bufferview = gltf["bufferViews"][(int)tex_accessor["bufferView"]];

			int vertex_count = vertex_accessor["count"];
			int tex_count = tex_accessor["count"];
			int vertex_stride = vertex_bufferview.contains("byteStride") ? (int)vertex_bufferview["byteStride"] : 12;
			int tex_stride = tex_bufferview.contains("byteStride") ? (int)tex_bufferview["byteStride"] : 8;
		
			int vertex_accessor_offset = vertex_accessor.contains("byteOffset") ? (int)vertex_accessor["byteOffset"] : 0;
			int tex_accessor_offset = tex_accessor.contains("byteOffset") ? (int)tex_accessor["byteOffset"] : 0;
		
			int vertex_start = vertex_bufferview["byteOffset"] + vertex_accessor_offset;
			int tex_start = tex_bufferview["byteOffset"] + tex_accessor_offset;

			current_mesh.SetDataCount(3 * vertex_count + 2 * tex_count);
			current_mesh.SetTextureOffset(3 * vertex_count * sizeof(float));
			current_mesh.vertices = new float[3 * vertex_count + 2 * tex_count];

			for (int i = 0, j = 0; i < vertex_count; ++i, j += 3)
			{
				current_mesh.vertices[j] = *(float*)(ptr_buffer + vertex_start + i * vertex_stride);
				current_mesh.vertices[j + 1] = *(float*)(ptr_buffer + vertex_start + i * vertex_stride + 4);
				current_mesh.vertices[j + 2] = *(float*)(ptr_buffer + vertex_start + i * vertex_stride + 8);
			}

			for (int i = 0, j = vertex_count * 3; i < tex_count; ++i, j += 2)
			{
				current_mesh.vertices[j] = *(float*)(ptr_buffer + tex_start + i * tex_stride);
				current_mesh.vertices[j + 1] = *(float*)(ptr_buffer + tex_start + i * tex_stride + 4);
			}
		}

		{
			auto& material = gltf["materials"][(int)mesh["primitives"][0]["material"]];
			auto& texture = gltf["textures"][(int)material["pbrMetallicRoughness"]["baseColorTexture"]["index"]];

			current_mesh.LoadTexture(path + std::string(gltf["images"][(int)texture["source"]]["uri"]));
		}

		current_mesh.Load();
		current_mesh.Free();
	}
}

void GLTFLoader::LoadBuffer(const std::string& path, std::vector<unsigned char>& buffer)
{
	std::ifstream file(path, std::ios::in | std::ios::binary);

	file.read((char*)buffer.data(), buffer.capacity());

	file.close();
}
