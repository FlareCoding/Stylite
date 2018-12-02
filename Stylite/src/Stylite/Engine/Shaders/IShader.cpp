#include "IShader.h"
#define GLEW_STATIC
#include <GLEW/glew.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

namespace Stylite
{
	void IShader::Start()
	{
		glUseProgram(programID);
	}

	void IShader::Stop()
	{
		glUseProgram(0);
	}

	void IShader::Delete()
	{
		glUseProgram(0);
		glDetachShader(programID, vertexShaderID);
		glDetachShader(programID, fragmentShaderID);
		glDeleteShader(vertexShaderID);
		glDeleteShader(fragmentShaderID);
		glDeleteProgram(programID);
	}

	unsigned int IShader::GetID()
	{
		return this->programID;
	}

	Uniform* IShader::GetUniform(const std::string& name)
	{
		size_t index =
			std::find_if(uniforms.begin(), uniforms.end(),
				[&name](const Uniform& uniform) { return uniform.m_Name._Equal(name); }) - uniforms.begin();

		if (index < uniforms.size())
			return &uniforms.at(index);
		else
			return nullptr;
	}

	void IShader::BindAttribute(int attribute, const char * variable)
	{
		glBindAttribLocation(programID, attribute, variable);
	}

	unsigned int IShader::GetUniformLocation(const char * name)
	{
		return glGetUniformLocation(programID, name);
	}

	unsigned int IShader::CreateShader(const char * filepath, unsigned int type)
	{
		std::string shaderCode;
		std::ifstream shaderFile;
		shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		try
		{
			shaderFile.open(filepath);
			std::stringstream shaderStream;
			shaderStream << shaderFile.rdbuf();
			shaderFile.close();
			shaderCode = shaderStream.str();
		}
		catch (std::ifstream::failure e)
		{
			std::cout << "Failed to shader source: " << filepath << "\n";
		}
		const char* Code = shaderCode.c_str();
		unsigned int shaderID;
		shaderID = glCreateShader(type);
		glShaderSource(shaderID, 1, &Code, NULL);
		glCompileShader(shaderID);
		CheckCompileErrors(shaderID, "Shader");

		return shaderID;
	}

	unsigned int IShader::CreateProgram()
	{
		unsigned int programID = glCreateProgram();
		glAttachShader(programID, vertexShaderID);
		glAttachShader(programID, fragmentShaderID);
		glLinkProgram(programID);
		glValidateProgram(programID);
		return programID;
	}

	void IShader::SetupShader(const char * VERTEX_FILE, const char * FRAGMENT_FILE)
	{
		vertexShaderID = CreateShader(VERTEX_FILE, GL_VERTEX_SHADER);
		fragmentShaderID = CreateShader(FRAGMENT_FILE, GL_FRAGMENT_SHADER);
		programID = CreateProgram();
	}

	void IShader::CheckCompileErrors(unsigned int shader, std::string type)
	{
		int success;
		char infoLog[1024];
		if (type != "PROGRAM")
		{
			glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(shader, 1024, NULL, infoLog);
				std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
			}
		}
		else
		{
			glGetProgramiv(shader, GL_LINK_STATUS, &success);
			if (!success)
			{
				glGetProgramInfoLog(shader, 1024, NULL, infoLog);
				std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
			}
		}
	}
}
