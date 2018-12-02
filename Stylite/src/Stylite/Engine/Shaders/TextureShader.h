#pragma once
#include "IShader.h"
#include "../../Config/Configuration.h"

namespace Stylite
{
	class TextureShader : public IShader
	{
	public:
		TextureShader();
		~TextureShader();

	private:
		void BindAttributes();
		void MapUniforms();
	};
}
