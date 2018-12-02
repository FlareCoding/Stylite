#pragma once
#include "IComponent.h"
#include <string>

namespace Stylite
{
	enum ShaderType
	{
		_BasicShader,
		_TextureShader
	};

	class STYLITE_API ShaderComponent : public IComponent
	{
	public:
		ShaderComponent();
		ShaderComponent(ShaderType _type);

		ShaderType shader_type;

		~ShaderComponent();
	};
}
