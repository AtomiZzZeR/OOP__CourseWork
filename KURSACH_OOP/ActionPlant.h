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
			cout << "������� ����� ������� ��������: ";
			cin >> deleteNumStr;

			try
			{
				deleteNum = stoi(deleteNumStr);
			}
			catch (...)
			{

				cout << "������ �����, ��� ������� ����� �����������! ��������� ����...\n" << endl;
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
			cout << "\n�������� � ����� �������� ��� � ������!" << endl;
			return;
		}
		cout << "\n�������� ������� ��������!\n" << endl;

		Vector::plants.erase(Vector::plants.begin() + delElem);
	}
};

