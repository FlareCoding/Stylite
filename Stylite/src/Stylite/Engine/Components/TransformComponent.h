#pragma once
#include "../Math/Mathematics.h"

namespace Stylite
{
	class TransformComponent
	{
	public:
		STYLITE_API TransformComponent();

		vec3	position	= vec3(0, 0, 0);
		float	rotation	= 0;
		vec2	scale		= vec2(1, 1);

		STYLITE_API mat4 GetTransformMatrix();
		STYLITE_API vec2 GetDirectionVector();

		STYLITE_API ~TransformComponent();
	};

}
