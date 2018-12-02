#pragma once
#include "Shaders.h"
#include "../Components/ShaderComponent.h"
#include <map>

namespace Stylite
{
	class ShaderManager
	{
	public:
		ShaderManager();
		void Initialize();

		IShader* GetShader(ShaderType _type);

		void Shutdown();
		~ShaderManager();

	private:
		std::map<ShaderType, IShader*> shaders;
	};
}
