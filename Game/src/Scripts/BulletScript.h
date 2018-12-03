#pragma once
#include "Stylite.h"
using namespace Stylite;

float RandomFloat(float a, float b);

class BulletScript : public ScriptComponent
{
public:
	BulletScript(std::vector<Entity*>& asteroids);

	void OnUpdate();

	~BulletScript();

private:
	std::vector<Entity*>& asteroids;
	double startTime;
	double currentTime;
	double lifeTime = 1.6;
};

