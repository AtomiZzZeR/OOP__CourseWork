#pragma once

#include <iostream>
#include "Vector.h"

using namespace std;

class ActionShow
{
public:
	void ShowPlants() {
		cout << "������ ��������:\n" << endl;

		for (int i = 0; i < Vector::plants.size(); i++) {
			cout << "�������� ������� �������: " << i << endl;
			cout << "��������: " << Vector::plants[i].GetCharacter().GetNamePlant() << endl;
			cout << "���������: " << Vector::plants[i].GetCharacter().GetFamily() << endl;
			cout << "����������� ���: " << Vector::plants[i].GetCharacter().GetType() << endl;
			cout << "�����: " << Vector::plants[i].GetCharacter().GetDepartment() << endl;
			cout << "����������� ���������: " << Vector::plants[i].GetCharacter().GetTemperature() << endl;
			cout << "�������� �� ��������: " << Vector::plants[i].GetCharacter().GetHybrid() << endl;
			cout << "������ ��������: " << Vector::plants[i].GetPeriod().GetPeriod2() << " �����(��)�" << endl;
			cout << "\n";
		}
	}

	void ShowPlants(vector<Plant> plants)
	{
		cout << "������ ��������:\n" << endl;

		for (int i = 0; i < plants.size(); i++) {
			cout << "�������� ������� �������: " << i << endl;
			cout << "��������: " << plants[i].GetCharacter().GetNamePlant() << endl;
			cout << "���������: " << plants[i].GetCharacter().GetFamily() << endl;
			cout << "����������� ���: " << plants[i].GetCharacter().GetType() << endl;
			cout << "�����: " << plants[i].GetCharacter().GetDepartment() << endl;
			cout << "����������� ���������: " << plants[i].GetCharacter().GetTemperature() << endl;
			cout << "�������� �� ��������: " << plants[i].GetCharacter().GetHybrid() << endl;
			cout << "������ ��������: " << plants[i].GetPeriod().GetPeriod2() << " �����(��)�" << endl;
			cout << "\n";
		}
	}
};

