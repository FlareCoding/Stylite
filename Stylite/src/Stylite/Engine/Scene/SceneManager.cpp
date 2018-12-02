#include "SceneManager.h"

namespace Stylite
{
	static std::vector<Scene*> scene_pool;
	Scene* current_scene = nullptr;

	STYLITE_API Scene* CreateScene()
	{
		Scene* scene = new Scene();
		scene_pool.push_back(scene);
		return scene;
	}

	STYLITE_API void DeleteScene(Scene* scene)
	{
		size_t idx = std::find(scene_pool.begin(), scene_pool.end(), scene) - scene_pool.begin();
		if (idx < scene_pool.size())
		{
			if (current_scene == scene) current_scene = nullptr;
			delete scene_pool.at(idx);
			scene_pool.erase(scene_pool.begin() + idx);
		}
	}

	STYLITE_API void DeleteAllScenes()
	{
		for (size_t i = 0; i < scene_pool.size(); i++)
			delete scene_pool.at(i);
		scene_pool.clear();
		current_scene = nullptr;
	}

	STYLITE_API Scene* GetActiveScene()
	{
		return current_scene;
	}

	STYLITE_API void SetActiveScene(Scene* scene)
	{
		current_scene = scene;
	}
}
