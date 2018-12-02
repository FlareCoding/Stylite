#include "Texture.h"
#define GLEW_STATIC
#include <GLEW/glew.h>

namespace Stylite
{
	void Texture::bind(unsigned int texture_unit)
	{
		glActiveTexture(texture_unit);
		glBindTexture(GL_TEXTURE_2D, id);
	}

	void Texture::unbind()
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void Texture::delete_texture()
	{
		glDeleteTextures(1, &id);
	}
}
