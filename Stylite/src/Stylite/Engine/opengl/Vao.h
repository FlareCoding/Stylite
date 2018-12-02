#pragma once
#include <vector>
#include <stdarg.h>
#include "Vbo.h"

namespace Stylite
{
	class Vao
	{
	public:
		Vao();

		void bind();
		void unbind();

		// stores data in a GL_ELEMENT_ELEMENT_BUFFER
		void addIndicesBuffer(std::vector<int>& indices);
		// updates data in a GL_ELEMENT_ELEMENT_BUFFER
		void updateIndicesBuffer(std::vector<int>& indices);

		// stores float data in one of the attribute lists of a vao
		void addStaticAttributef(int attribNum, int coordinateSize, std::vector<float>& data);
		// stores int data in one of the attribute lists of a vao
		void addStaticAttributei(int attribNum, int coordinateSize, std::vector<int>& data);

		// stores float data in one of the attribute lists of a vao
		void addDynamicAttributef(int attribNum, int coordinateSize, std::vector<float>& data);
		// stores int data in one of the attribute lists of a vao
		void addDynamicAttributei(int attribNum, int coordinateSize, std::vector<int>& data);

		// updates float data in the already existing vertex buffer object
		void updateVboDataf(int attribNum, int coordinateSize, std::vector<float>& data);
		// updates int data in the already existing vertex buffer object
		void updateVboDatai(int attribNum, int coordinateSize, std::vector<int>& data);

		// enables vao attributes. requires the number of attributes, and then their indexes
		void enableAttribs(int count, ...);
		// disables vao attributes. requires the number of attributes, and then their indexes
		void disableAttribs(int count, ...);

		// get vertex count to start drawing
		int getVertexCount() { return this->vertexCount; }

		// get id of the vao
		unsigned int getID() { return this->id; }

		void remove();

		~Vao();

	private:
		unsigned int id;
		int vertexCount;
		std::vector<Vbo> buffers;
		Vbo indexBuffer = Vbo(GL_ELEMENT_ARRAY_BUFFER);
		void createVao();
	};
}
