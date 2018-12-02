#include "Uniform.h"
#define GLEW_STATIC
#include <GLEW/glew.h>
#include "../IShader.h"

namespace Stylite
{
	Uniform::Uniform(IShader* _shader, const std::string _name) : m_Name(_name)
	{
		this->m_Location = glGetUniformLocation(_shader->GetID(), _name.c_str());
	}

	const bool Uniform::IsValid()
	{
		return this->m_Location != -1;
	}

	void Uniform::Set(mat4 val)
	{
		glUniformMatrix4fv(m_Location, 1, GL_FALSE, &val.m00);
	}

	void Uniform::Set(vec4 val)
	{
		glUniform4f(m_Location, val.x, val.y, val.z, val.w);
	}

	void Uniform::Set(vec3 val)
	{
		glUniform3f(m_Location, val.x, val.y, val.z);
	}

	void Uniform::Set(vec2 val)
	{
		glUniform2f(m_Location, val.x, val.y);
	}

	void Uniform::Set(vec4i val)
	{
		glUniform4i(m_Location, val.x, val.y, val.z, val.w);
	}

	void Uniform::Set(vec3i val)
	{
		glUniform3i(m_Location, val.x, val.y, val.z);
	}

	void Uniform::Set(vec2i val)
	{
		glUniform2i(m_Location, val.x, val.y);
	}

	void Uniform::Set(vec4d val)
	{
		glUniform4d(m_Location, val.x, val.y, val.z, val.w);
	}

	void Uniform::Set(vec3d val)
	{
		glUniform3d(m_Location, val.x, val.y, val.z);
	}

	void Uniform::Set(vec2d val)
	{
		glUniform2d(m_Location, val.x, val.y);
	}

	void Uniform::Set(int val)
	{
		glUniform1i(m_Location, val);
	}

	void Uniform::Set(float val)
	{
		glUniform1f(m_Location, val);
	}

	void Uniform::Set(double val)
	{
		glUniform1d(m_Location, val);
	}

	void Uniform::Set(bool val)
	{
		glUniform1f(m_Location, val ? 1.0f : 0.0f);
	}

	Uniform::~Uniform()
	{
	}
}
