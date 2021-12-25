#pragma once
#include "Plant.h"
#include <algorithm>
#include "ActionShow.h"

using namespace std;

class ActionSort
{
public:
	void SortPlantsDescending()
	{
		vector<Plant> plants = Vector::plants;

		sort(plants.begin(), plants.end(), [](Plant a, Plant b)
			{
				return a.GetPeriod().GetPeriod2() > b.GetPeriod().GetPeriod2();
			});

		ActionShow show;
		show.ShowPlants(plants);
	}

	void  SortPlantsAscending()
	{
		vector<Plant> plants = Vector::plants;

		sort(plants.begin(), plants.end(), [](Plant a, Plant b)
			{
				return a.GetPeriod().GetPeriod2() < b.GetPeriod().GetPeriod2();
			});

		ActionShow show;
		show.ShowPlants(plants);
	}
};



