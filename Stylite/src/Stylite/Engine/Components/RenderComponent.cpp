#include "RenderComponent.h"
#include "../opengl/Vao.h"
#include <iostream>

namespace Stylite
{
	RenderComponent::RenderComponent(Mesh mesh, Texture* texture)
	{
		vao = new Vao();
		vao->bind();
		vao->addDynamicAttributef(0, 2, mesh.vertices);
		m_VertexCount = mesh.vertices.size() / 2;
		
		if (mesh.uvs.size() > 0) vao->addDynamicAttributef(1, 2, mesh.uvs);
		if (mesh.indices.size() > 0)
		{
			vao->addIndicesBuffer(mesh.indices);
			m_VertexCount = vao->getVertexCount();
			bHasIndices = true;
		}

		vao->unbind();

		this->mesh = mesh;
		if (texture != nullptr)
			this->texture = *texture;
	}

	RenderComponent::~RenderComponent()
	{
		delete vao;
	}
}
