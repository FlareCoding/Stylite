#pragma once
#include "../../Math/Mathematics.h"
#include <string>

namespace Stylite
{
	class IShader;

	class Uniform
	{
	public:
		Uniform(IShader* _shader, const std::string _name);
		
		unsigned int		m_Location;
		const std::string	m_Name;
		const bool IsValid();

		void Set(mat4 val);
		void Set(vec4 val);
		void Set(vec3 val);
		void Set(vec2 val);
		void Set(vec4i val);
		void Set(vec3i val);
		void Set(vec2i val);
		void Set(vec4d val);
		void Set(vec3d val);
		void Set(vec2d val);
		void Set(int val);
		void Set(float val);
		void Set(double val);
		void Set(bool val);

		virtual ~Uniform();
	};
}
