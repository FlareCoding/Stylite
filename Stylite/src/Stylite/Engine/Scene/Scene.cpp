#include "Scene.h"


namespace Stylite
{
	Scene::Scene()
	{
		m_entities = new std::vector<Entity*>();
	}

	void Scene::AddEntity(Entity* e)
	{
		m_entities->push_back(e);
	}

	void Scene::RemoveEntity(Entity* e)
	{
		size_t index = std::find(m_entities->begin(), m_entities->end(), e) - m_entities->begin();
		if (index < m_entities->size())
			m_entities->erase(m_entities->begin() + index);
	}

	Scene::~Scene()
	{
		delete m_entities;
	}
}
