#pragma once
#include "IShader.h"
#include "../../Config/Configuration.h"

namespace Stylite
{
	class BasicShader : public IShader
	{
	public:
		BasicShader();
		~BasicShader();

	private:
		void BindAttributes();
		void MapUniforms();
	};
}
