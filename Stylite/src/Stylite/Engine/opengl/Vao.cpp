#include "Vao.h"

namespace Stylite
{
	Vao::Vao()
	{
		createVao();
	}

	Vao::~Vao()
	{

	}

	void Vao::createVao()
	{
		glGenVertexArrays(1, &id);
	}

	void Vao::bind()
	{
		glBindVertexArray(id);
	}

	void Vao::unbind()
	{
		glBindVertexArray(0);
	}

	void Vao::remove()
	{
		for (Vbo vbo : buffers)
		{
			vbo.remove();
		}
		glDeleteVertexArrays(1, &id);
	}

	void Vao::addIndicesBuffer(std::vector<int>& indices)
	{
		vertexCount = indices.size();
		indexBuffer = Vbo(GL_ELEMENT_ARRAY_BUFFER);
		indexBuffer.bind();
		indexBuffer.storeStaticData(indices);
	}

	void Vao::updateIndicesBuffer(std::vector<int>& indices)
	{
		vertexCount = indices.size();
		indexBuffer.bind();
		indexBuffer.storeStreamDrawData(indices);
	}

	void Vao::addStaticAttributef(int attribNum, int coordinateSize, std::vector<float>& data)
	{
		Vbo vbo = Vbo(GL_ARRAY_BUFFER);
		vbo.bind();
		vbo.storeStaticData(data);
		glVertexAttribPointer(attribNum, coordinateSize, GL_FLOAT, false, 0, (void*)0);
		vbo.unbind();
		buffers.push_back(vbo);
	}

	void Vao::addStaticAttributei(int attribNum, int coordinateSize, std::vector<int>& data)
	{
		Vbo vbo = Vbo(GL_ARRAY_BUFFER);
		vbo.bind();
		vbo.storeStaticData(data);
		glVertexAttribIPointer(attribNum, coordinateSize, GL_INT, 0, (void*)0);
		vbo.unbind();
		buffers.push_back(vbo);
	}

	void Vao::addDynamicAttributef(int attribNum, int coordinateSize, std::vector<float>& data)
	{
		Vbo vbo = Vbo(GL_ARRAY_BUFFER);
		vbo.bind();
		vbo.storeDynamicData(data);
		glVertexAttribPointer(attribNum, coordinateSize, GL_FLOAT, false, 0, (void*)0);
		vbo.unbind();
		buffers.push_back(vbo);
	}

	void Vao::addDynamicAttributei(int attribNum, int coordinateSize, std::vector<int>& data)
	{
		Vbo vbo = Vbo(GL_ARRAY_BUFFER);
		vbo.bind();
		vbo.storeDynamicData(data);
		glVertexAttribIPointer(attribNum, coordinateSize, GL_INT, 0, (void*)0);
		vbo.unbind();
		buffers.push_back(vbo);
	}

	void Vao::updateVboDataf(int attribNum, int coordinateSize, std::vector<float>& data)
	{
		Vbo& vbo = buffers.at(attribNum);
		vbo.bind();
		vbo.storeStreamDrawData(data);
		glVertexAttribPointer(attribNum, coordinateSize, GL_FLOAT, false, 0, (void*)0);
		vbo.unbind();
	}

	void Vao::updateVboDatai(int attribNum, int coordinateSize, std::vector<int>& data)
	{
		Vbo& vbo = buffers.at(attribNum);
		vbo.bind();
		vbo.storeStreamDrawData(data);
		glVertexAttribPointer(attribNum, coordinateSize, GL_INT, false, 0, (void*)0);
		vbo.unbind();
	}

	void Vao::enableAttribs(int count, ...)
	{
		va_list arguments;
		va_start(arguments, count);
		for (int i = 0; i < count; i++)
		{
			int attrib = va_arg(arguments, int);
			glEnableVertexAttribArray(attrib);
		}
		va_end(arguments);
	}

	void Vao::disableAttribs(int count, ...)
	{
		va_list arguments;
		va_start(arguments, count);
		for (int i = 0; i < count; i++)
		{
			int attrib = va_arg(arguments, int);
			glDisableVertexAttribArray(attrib);
		}
		va_end(arguments);
	}
}
