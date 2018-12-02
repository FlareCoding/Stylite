#pragma once
#include "Stylite.h"
using namespace Stylite;

class AsteroidScript : public Stylite::ScriptComponent
{
public:
	AsteroidScript();

	void OnUpdate();

	~AsteroidScript();

private:
	float size = 10;
};

