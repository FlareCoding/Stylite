#pragma once
#include <vector>
#include "../Math/Mathematics.h"
#include "Uniforms/Uniform.h"

namespace Stylite
{
	class IShader
	{
	public:

		void Start();
		void Stop();
		void Delete();
		unsigned int GetID();
		Uniform* GetUniform(const std::string& name);

	protected:
		unsigned int programID, vertexShaderID, fragmentShaderID;
		std::vector<Uniform> uniforms;
		
		void BindAttribute(int attribute, const char* variable);
		unsigned int GetUniformLocation(const char* name);

		virtual void BindAttributes() = 0;
		virtual void MapUniforms() = 0;

		unsigned int CreateShader(const char* filepath, unsigned int type);
		unsigned int CreateProgram();
		void SetupShader(const char* VERTEX_FILE, const char* FRAGMENT_FILE);

	private:
		void CheckCompileErrors(unsigned int shader, std::string type);
	};
}
