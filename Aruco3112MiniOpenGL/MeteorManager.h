#pragma once

#include "Vector.h"
#include <vector>
using namespace std;
class MeteorManager
{
protected :
	vector<float> timeManager;
	vector<Vector3> meteorCoordonateManager;
	int nbMeteor;
public:
	vector<Vector3> GetMeteorCoordonateManager(){ return meteorCoordonateManager; };
	void Update();
	void addMeteor(float x, float y, float z);
	int getNbMeteor() { return nbMeteor; };
	MeteorManager();
};

