#include "TimeManager.h"

TimeManager::TimeManager()
{
	time = 0;
}

void TimeManager::Update()
{
	time += 1 ;
}

int TimeManager::getTime()
{
	return time;
}
