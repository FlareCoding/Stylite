#include "BasicShader.h"

namespace Stylite
{
	BasicShader::BasicShader()
	{
		std::string dir = Settings::Engine::Shaders::SRC_PATH;
		SetupShader((dir + "BasicShader_vs.glsl").c_str(), (dir + "BasicShader_fs.glsl").c_str());
		BindAttributes();
		MapUniforms();
	}

	BasicShader::~BasicShader()
	{
	}

	void BasicShader::BindAttributes()
	{
		BindAttribute(0, "vertexPosition");
	}
	
	void BasicShader::MapUniforms()
	{
		Uniform transformation_matrix = Uniform(this, "transformation_matrix");
		if (transformation_matrix.IsValid()) uniforms.push_back(transformation_matrix);

		Uniform projection_matrix = Uniform(this, "projection_matrix");
		if (projection_matrix.IsValid()) uniforms.push_back(projection_matrix);
	}
}
