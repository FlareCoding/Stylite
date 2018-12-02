#pragma once
#include "Stylite.h"
using namespace Stylite;

class BulletScript : public ScriptComponent
{
public:
	BulletScript();

	void OnUpdate();

	~BulletScript();

private:
	double startTime;
	double currentTime;
	double lifeTime = 1.6;
};

