#include "Vector4.h"

namespace Stylite
{

	Color::Color() : Vector4<float>()
	{
	}

	Color::Color(float r, float g, float b, float a) : Vector4<float>(r, g, b, a)
	{
	}

	Color Color::OpenGLFormat()
	{
		return Color(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
	}
}
