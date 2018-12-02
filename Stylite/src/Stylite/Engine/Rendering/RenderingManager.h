#pragma once
#include "../Shaders/Shaders.h"
#include "../Scene/Scene.h"
#include "../Components/RenderComponent.h"
#include "../Components/TransformComponent.h"

namespace Stylite
{
	class Display;

	class RenderingManager
	{
	public:
		RenderingManager();
		void Initialize(Display* display);
		void SetWireframe(bool state);

		void Update();
		void Render(RenderComponent* _RenderComponent, IShader* _Shader);

		void Shutdown();
		~RenderingManager();

	private:
		void ClearBuffers();
		void ClearColor();
		mat4 projection_matrix;
	};

}
