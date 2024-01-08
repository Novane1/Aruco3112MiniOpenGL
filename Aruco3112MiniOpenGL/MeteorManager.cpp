#include "MeteorManager.h"

void MeteorManager::Update()
{
	for (int i = 0; i < meteorCoordonateManager.size(); i++) {
		if (timeManager[i] < 0.6f)
		{
			meteorCoordonateManager[i].setZ(meteorCoordonateManager[i].getZ() - 0.01);
			timeManager[i] = timeManager[i] + 0.01;
			
		}
		else 
		{
			
			float randomX = static_cast<float>(rand() % 10) / 30;

			float randomY = static_cast<float>(rand() % 10) / 30;
			if (rand() % 2 ==1) {
				randomX = -randomX;
			}
			if (rand() % 2 ==1) {
				randomY = -randomY;
			}
			meteorCoordonateManager[i].setX(randomX);
			meteorCoordonateManager[i].setY(randomY);
			meteorCoordonateManager[i].setZ(0.3f);
			timeManager[i] = 0;
		}
		
	}
}

void MeteorManager::addMeteor(float x, float y, float z)
{
	if (nbMeteor < 6) {
		nbMeteor++;
		Vector3 temp(x, y, z);
		meteorCoordonateManager.push_back(temp);
		timeManager.push_back(0);
	}
	
}

MeteorManager::MeteorManager()
{
	nbMeteor = 1;
}
