#pragma once

namespace Stylite
{
	struct Texture
	{
		unsigned int id = 0;
		bool transparent = false;
		void bind(unsigned int texture_unit);
		void unbind();
		void delete_texture();
	};
}