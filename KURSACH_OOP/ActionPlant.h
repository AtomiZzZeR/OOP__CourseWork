#pragma once

#include <iostream>
#include "Plant.h"
#include "Vector.h"
#include <windows.h>
#include "Period.h"

using namespace std;

class ActionPlant
{
private:
	int CheckCorrectDeleteNum()
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		string deleteNumStr;
		int deleteNum;
		bool flag = false;

		while (!flag)
		{
			cout << "Введите номер пометки растения: ";
			cin >> deleteNumStr;

			try
			{
				deleteNum = stoi(deleteNumStr);
			}
			catch (...)
			{

				cout << "Ошибка ввода, выш ведённым номер некорректен! Повторите ввод...\n" << endl;
				flag = false;
				continue;
			}

			flag = true;
		}

		return deleteNum;
	}

public:
	void AddPlant() {
		CharacterPlant character;
		character.SetCharacterPlant();

		Period period;
		period.SetPeriod();

		Plant plant;
		plant.SetPlant(character, period);

		Vector::plants.push_back(plant);
	}

	void DeletePlant() {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		int delElem = CheckCorrectDeleteNum();


		if (delElem < 0 || delElem >= Vector::plants.size()) {
			cout << "\nРастения с такой пометкой нет в списке!" << endl;
			return;
		}
		cout << "\nРастение успешно выкопано!\n" << endl;

		Vector::plants.erase(Vector::plants.begin() + delElem);
	}
};

