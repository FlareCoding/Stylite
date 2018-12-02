#include "TransformComponent.h"

namespace Stylite
{
	TransformComponent::TransformComponent()
	{
	}

	TransformComponent::~TransformComponent()
	{
	}

	mat4 TransformComponent::GetTransformMatrix()
	{
		mat4 matrix(1.0f);
		matrix = matrix.Translate(position);
		matrix = matrix.Rotate(radians(rotation), vec3(0, 0, 1));
		matrix = matrix.Scale(vec3(scale.x, scale.y, 1.0f));
		return matrix;
	}

	vec2 TransformComponent::GetDirectionVector()
	{
		return vec2::FrontVector.Rotate(rotation);
	}
}
