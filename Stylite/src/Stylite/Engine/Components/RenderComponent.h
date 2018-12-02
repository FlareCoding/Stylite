#pragma once
#include "IComponent.h"
#include "../MeshData/Mesh.h"
#include "../Utils/Utility.h"

namespace Stylite
{
	class Vao;

	class STYLITE_API RenderComponent : public IComponent
	{
	public:
		RenderComponent(Mesh mesh, Texture* texture);

		Vao* GetVao() { return this->vao; }
		const unsigned int GetVertexCount() const { return this->m_VertexCount; }
		const bool HasIndices() const { return this->bHasIndices; }

		Mesh mesh;
		Texture texture;

		~RenderComponent();

	private:
		Mesh m_Mesh;
		Vao* vao;
		unsigned int m_VertexCount = 0;
		bool bHasIndices = false;
	};
}

