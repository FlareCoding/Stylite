#include "TextureShader.h"

namespace Stylite
{
	TextureShader::TextureShader()
	{
		std::string dir = Settings::Engine::Shaders::SRC_PATH;
		SetupShader((dir + "TextureShader_vs.glsl").c_str(), (dir + "TextureShader_fs.glsl").c_str());
		BindAttributes();
		MapUniforms();
	}

	TextureShader::~TextureShader()
	{
	}

	void TextureShader::BindAttributes()
	{
		BindAttribute(0, "vertexPosition");
	}

	void TextureShader::MapUniforms()
	{
		Uniform transformation_matrix = Uniform(this, "transformation_matrix");
		if (transformation_matrix.IsValid()) uniforms.push_back(transformation_matrix);

		Uniform projection_matrix = Uniform(this, "projection_matrix");
		if (projection_matrix.IsValid()) uniforms.push_back(projection_matrix);

		Uniform texture_transparency = Uniform(this, "texture_transparency");
		if (texture_transparency.IsValid()) uniforms.push_back(texture_transparency);
	}
}
