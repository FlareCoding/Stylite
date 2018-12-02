#include "RenderingManager.h"
#include "../../Display/Display.h"
#include "../opengl/Vao.h"
#include <thread>
#include <GLEW/glew.h>

namespace Stylite
{
	RenderingManager::RenderingManager()
	{
	}

	RenderingManager::~RenderingManager()
	{
	}

	void RenderingManager::ClearBuffers()
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void RenderingManager::ClearColor()
	{
		glClearColor(0.009f, 0.009f, 0.043f, 1.0f);
	}

	void RenderingManager::Initialize(Display* display)
	{
		display->CreateOpenglContext();
		glewInit();
		projection_matrix = mat4::Orthographic(0, (float)Settings::Display::DisplayWidth, 0, (float)Settings::Display::DisplayHeight);
		if (Settings::OpenGL::AntiAliasing)
			glEnable(GL_MULTISAMPLE);
	}

	void RenderingManager::SetWireframe(bool state)
	{
		if (state)
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		else
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}

	void RenderingManager::Update()
	{
		ClearBuffers();
		ClearColor();
	}

	void RenderingManager::Render(RenderComponent* _RenderComponent, IShader* _Shader)
	{
		_Shader->Start();

		Vao* vao = _RenderComponent->GetVao();
		if (vao == nullptr || vao->getID() == 0) return;
		vao->bind();
		vao->enableAttribs(2, 0, 1);
		_RenderComponent->texture.bind(GL_TEXTURE0);

		if (_RenderComponent->texture.transparent)
		{
			Uniform* texture_transparency = _Shader->GetUniform("texture_transparency");
			if (texture_transparency)
				texture_transparency->Set(1.0f);
		}

		Uniform* transform = _Shader->GetUniform("transformation_matrix");
		if (transform)
			transform->Set(_RenderComponent->owner->transform->GetTransformMatrix());

		Uniform* projection = _Shader->GetUniform("projection_matrix");
		if (projection)
			projection->Set(projection_matrix);

		if (_RenderComponent->HasIndices())
			glDrawElements(GL_TRIANGLES, _RenderComponent->GetVertexCount(), GL_UNSIGNED_INT, 0);
		else
			glDrawArrays(GL_TRIANGLES, 0, _RenderComponent->GetVertexCount());

		_RenderComponent->texture.unbind();
		vao->disableAttribs(2, 0, 1);
		vao->unbind();

		_Shader->Stop();
	}

	void RenderingManager::Shutdown()
	{	
	}
}
