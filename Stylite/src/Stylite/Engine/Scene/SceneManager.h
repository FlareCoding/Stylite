#pragma once
#include "../../api_build.h"
#include "Scene.h"

namespace Stylite
{
	STYLITE_API Scene*	CreateScene();
	STYLITE_API void	DeleteScene(Scene* scene);
	STYLITE_API void	DeleteAllScenes();

	STYLITE_API Scene*	GetActiveScene();
	STYLITE_API void	SetActiveScene(Scene* scene);
}
