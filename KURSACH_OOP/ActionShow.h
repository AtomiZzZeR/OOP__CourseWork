#pragma once

#include <iostream>
#include "Vector.h"

using namespace std;

class ActionShow
{
public:
	void ShowPlants() {
		cout << "Список растений:\n" << endl;

		for (int i = 0; i < Vector::plants.size(); i++) {
			cout << "Растение имеющее пометку: " << i << endl;
			cout << "Название: " << Vector::plants[i].GetCharacter().GetNamePlant() << endl;
			cout << "Семейство: " << Vector::plants[i].GetCharacter().GetFamily() << endl;
			cout << "Назначенный тип: " << Vector::plants[i].GetCharacter().GetType() << endl;
			cout << "Отдел: " << Vector::plants[i].GetCharacter().GetDepartment() << endl;
			cout << "Температура окружения: " << Vector::plants[i].GetCharacter().GetTemperature() << endl;
			cout << "Является ли гибридом: " << Vector::plants[i].GetCharacter().GetHybrid() << endl;
			cout << "Период цветения: " << Vector::plants[i].GetPeriod().GetPeriod2() << " месяц(ев)а" << endl;
			cout << "\n";
		}
	}

	void ShowPlants(vector<Plant> plants)
	{
		cout << "Список растений:\n" << endl;

		for (int i = 0; i < plants.size(); i++) {
			cout << "Растение имеющее пометку: " << i << endl;
			cout << "Название: " << plants[i].GetCharacter().GetNamePlant() << endl;
			cout << "Семейство: " << plants[i].GetCharacter().GetFamily() << endl;
			cout << "Назначенный тип: " << plants[i].GetCharacter().GetType() << endl;
			cout << "Отдел: " << plants[i].GetCharacter().GetDepartment() << endl;
			cout << "Температура окружения: " << plants[i].GetCharacter().GetTemperature() << endl;
			cout << "Является ли гибридом: " << plants[i].GetCharacter().GetHybrid() << endl;
			cout << "Период цветения: " << plants[i].GetPeriod().GetPeriod2() << " месяц(ев)а" << endl;
			cout << "\n";
		}
	}
};

