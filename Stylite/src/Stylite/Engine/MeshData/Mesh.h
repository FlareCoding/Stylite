#pragma once
#include <vector>

namespace Stylite
{
	struct Mesh
	{
		std::vector<float>	vertices;
		std::vector<float>	uvs;
		std::vector<int>	indices;
	};
}

