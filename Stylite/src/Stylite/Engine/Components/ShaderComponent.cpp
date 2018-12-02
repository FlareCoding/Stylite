#include "ShaderComponent.h"

namespace Stylite
{
	ShaderComponent::ShaderComponent() : shader_type(_BasicShader)
	{
	}

	ShaderComponent::ShaderComponent(ShaderType _type) : shader_type(_type)
	{
	}

	ShaderComponent::~ShaderComponent()
	{
	}
}
