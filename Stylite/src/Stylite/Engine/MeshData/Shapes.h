#pragma once
#include "../../api_build.h"
#include "Mesh.h"

namespace Stylite
{
	namespace Shapes
	{
		class STYLITE_API Rectangle : public Mesh
		{
		public:
			Rectangle(float width, float height);
		};

		class STYLITE_API Circle : public Mesh
		{
		public:
			Circle(float radius, size_t segments);
		};
	}
}
