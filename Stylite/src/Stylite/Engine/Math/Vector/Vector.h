#pragma once
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

namespace Stylite
{
	typedef Vector2<float>	Vector2f, vec2f, vec2;
	typedef Vector2<int>	Vector2i, vec2i;
	typedef Vector2<double>	Vector2d, vec2d;

	typedef Vector3<float>	Vector3f, vec3f, vec3;
	typedef Vector3<int>	Vector3i, vec3i;
	typedef Vector3<double>	Vector3d, vec3d;

	typedef Vector4<float>	Vector4f, vec4f, vec4;
	typedef Vector4<int>	Vector4i, vec4i;
	typedef Vector4<double>	Vector4d, vec4d;

	STYLITE_API float radians(float deg);
	STYLITE_API float degrees(float rad);
}
