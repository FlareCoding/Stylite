#include "Shapes.h"
#define PI 3.141592653589793f

namespace Stylite
{
	namespace Shapes
	{
		Rectangle::Rectangle(float width, float height)
		{
			this->vertices = {
				-width / 2,  height / 2,
				-width / 2, -height / 2,
				 width / 2,  height / 2,
				 width / 2, -height / 2
			};

			this->uvs = {
				0, 0,
				0, 1,
				1, 0,
				1, 1
			};

			this->indices = {
				0, 1, 2,
				2, 1, 3
			};
		}

		Circle::Circle(float radius, size_t segments)
		{
			// center point
			vertices.push_back(0);
			vertices.push_back(0);

			uvs.push_back(0.5f);
			uvs.push_back(0.5f);

			for (size_t i = 0; i <= segments; i++)
			{
				float angle = (360.0f / (float)segments) * (float)i;
				float xPos = radius * cosf(angle * (PI / 180.0f));
				float yPos = radius * sinf(angle * (PI / 180.0f));

				vertices.push_back(xPos);
				vertices.push_back(yPos);

				uvs.push_back(0.5f + (xPos / radius));
				uvs.push_back(0.5f + (yPos / radius));

				indices.push_back(0);
				indices.push_back(i + 1);
				indices.push_back(i + 2);
			}
		}
	}
}
