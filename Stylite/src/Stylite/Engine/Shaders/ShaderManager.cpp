#include "ShaderManager.h"

namespace Stylite
{
	ShaderManager::ShaderManager()
	{
	}

	ShaderManager::~ShaderManager()
	{
	}

	void ShaderManager::Initialize()
	{
		BasicShader* m_BasicShader = new BasicShader();
		TextureShader* m_TextureShader = new TextureShader();

		shaders.insert(std::pair<ShaderType, IShader*>(_BasicShader, m_BasicShader));
		shaders.insert(std::pair<ShaderType, IShader*>(_TextureShader, m_TextureShader));
	}

	IShader* ShaderManager::GetShader(ShaderType _type)
	{
		for (std::map<ShaderType, IShader*>::iterator it = shaders.begin(); it != shaders.end(); it++)
			if (it->first == _type)
				return it->second;
		return nullptr;
	}

	void ShaderManager::Shutdown()
	{
		for (std::map<ShaderType, IShader*>::iterator it = shaders.begin(); it != shaders.end(); it++)
		{
			it->second->Delete();
			delete it->second;
		}
	}
}
