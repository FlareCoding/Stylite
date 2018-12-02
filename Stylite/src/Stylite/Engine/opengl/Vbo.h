#pragma once
#define GLEW_STATIC
#include <GLEW/glew.h>
#include <vector>

namespace Stylite
{
	class Vbo
	{
	public:
		Vbo(int type);

		void bind();
		void unbind();

		void storeStaticData(std::vector<float>& data);
		void storeStaticData(std::vector<int>& data);

		void storeDynamicData(std::vector<float>& data);
		void storeDynamicData(std::vector<int>& data);

		void storeStreamDrawData(std::vector<float>& data);
		void storeStreamDrawData(std::vector<int>& data);

		void remove();

		~Vbo();
	private:
		unsigned int id;
		int type;
		void createVbo();
	};

}