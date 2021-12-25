#pragma once

#include <iostream>
#include <string>
#include "NamePlant.h"
#include <regex>

using namespace std;

class CharacterPlant : public NamePlant
{
private:
	// название есть
	char family[100];
	char type[100];
	char department[100];
	int temperature;
	char hybrid[100];

public:
	string GetFamily() {
		return family;
	}

	string GetType() {
		return type;
	}

	string GetDepartment() {
		return department;
	}

	int GetTemperature() {
		return temperature;
	}

	string GetHybrid() {
		return hybrid;
	}

	string GetCheckType() {
		string p_typeStr;
		bool flag = false;

		while (!flag) {
			cin >> p_typeStr;
			regex regular("Низшее|Высшее");

			try
			{
				if (!regex_match(p_typeStr, regular)) {
					throw 0;
				}

			}
			catch (...)
			{
				cout << "Недопустимое значение! Повторите ввод: ";
				flag = false;
				continue;
			}

			flag = true;
		}

		return p_typeStr;
	}

	string GetCheckDepartment() {
		string p_deparStr;
		bool flag = false;

		while (!flag) {
			cin >> p_deparStr;
			regex regular("Покрытосеменной|Цветковый");

			try
			{
				if (!regex_match(p_deparStr, regular)) {
					throw 0;
				}

			}
			catch (...)
			{
				cout << "Недопустимое значение! Повторите ввод: ";
				flag = false;
				continue;
			}

			flag = true;
		}

		return p_deparStr;
	}

	int GetCheckTemperature() {
		string tempStr;
		int temp;
		bool flag = false;

		while (!flag) {
			cin >> tempStr;

			try
			{
				temp = stoi(tempStr);

				if (temp < -10 || temp > 30) {
					throw 0;
				}
			}
			catch (...)
			{
				cout << "Недоступное значение! Повторите ввод: ";
				flag = false;
				continue;
			}

			flag = true;
		}

		return temp;
	}

	string GetCheckHybrid() {
		string p_hybridStr;
		bool flag = false;

		while (!flag) {
			cin >> p_hybridStr;
			regex regular("Да|Нет");

			try
			{
				if (!regex_match(p_hybridStr, regular)) {
					throw 0;
				}

			}
			catch (...)
			{
				cout << "Недопустимое значение! Повторите ввод: ";
				flag = false;
				continue;
			}

			flag = true;
		}

		return p_hybridStr;
	}

	void SetCharacterPlant() {
		cout << "Введите название растения: ";
		cin >> namePlant;
		cout << "\n";

		cout << "Введите семейство, принадлежащее растению: ";
		cin >> family;
		cout << "\n";

		cout << "Выберите тип растения (Низшее | Высшее): ";
		strcpy_s(type, GetCheckType().c_str());
		cout << "\n";

		cout << "Введите отдел растения (Покрытосеменной | Цветковый): ";
		strcpy_s(department, GetCheckDepartment().c_str());
		cout << "\n";

		cout << "Введите предпочитаемую температуру (от -10 до +30): ";
		temperature = GetCheckTemperature();
		cout << "\n";

		cout << "Является ли растение гибридом (Да | Нет): ";
		strcpy_s(hybrid, GetCheckHybrid().c_str());
		cout << "\n";
	}

	int GetCheckPlantNum() {
		string h_leavesStr;
		int h_leaves;
		bool flag = false;

		while (!flag) {
			cin >> h_leavesStr;

			try
			{
				h_leaves = stoi(h_leavesStr);

			}
			catch (...)
			{
				cout << "Недоступное значение! Повторите ввод: ";
				flag = false;
				continue;
			}

			flag = true;
		}

		return h_leaves;
	}
};

