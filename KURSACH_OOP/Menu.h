#pragma once

#include <iostream>
#include <string>
#include <Windows.h>
#include "ActionPlant.h"
#include "ActionShow.h"
#include "ActionFile.h"
#include "ActionSort.h"

using namespace std;

enum ConsoleColor {
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

class Menu
{
private:
	ActionPlant actionPlant;
	ActionShow actionShow;
	ActionFile actionFile;
	ActionSort actionSort;

public: 
	void MainMenu() {

		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | White));

		cout << "����� ���������� � ����! �������� ��������!\n\n";

		while (true) {
			cout << "1) �������� � ��������� ��������" << endl;
			cout << "2) �������� ������ �������" << endl;
			cout << "3) ����������� ������ �������" << endl;
			cout << "4) �������� �������� �� ���������" << endl;
			cout << "�������� �����" << endl;
			cout << "5) ���������� ����" << endl;
			cout << "6) ��������� ����" << endl;
			cout << "���. ���������" << endl;
			cout << "7) ��������� ������ ������� (BETA);" << endl;
			cout << "0) �����;" << endl;	

			cout << "\n";

			int menuNum = CheckCorrectMenuNum();
			cout << "\n";

			switch (menuNum) {
			case 1: {
				actionPlant.AddPlant();

				break;
			}
			case 2: {
				actionShow.ShowPlants();

				break;
			}
			case 3: {
				SortMenu();

				break;
			}
			case 4: {
				actionShow.ShowPlants();
				actionPlant.DeletePlant();

				break;
			}
			case 5: {
				actionFile.ReadFiles();

				cout << "���� ������� ��������!\n" << endl;

				break;
			}
			case 6: {
				actionFile.WriteFiles();

				cout << "���� ������� �������!\n" << endl;

				break;
			}
			case 7: {
				ChangeInterfaceColor();

				break;
			}
			case 0: {
				cout << "������������ �����...\n\n\n";
				return;
			}
			default: {
				
				if (menuNum < 0) {					
					cout << "����� �������� �� ����� ���� �������������! ��������� ��� ���...\n\n" << endl;							
				}
				else if (menuNum == 0)
				{	
					cout << "����� �������� �� ����� ���� ������ ����! ��������� ��� ���...\n\n" << endl;
				}
				else
				{		
					cout << "�������� ��� ����� ������ �� �������! ��������� ��� ���...\n\n" << endl;	
				}
				
				system("color 0F");
				break;
			}
			}
		}
	}

	int CheckCorrectMenuNum()
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		string menuNumErrorStr;
		int menuNum;
		bool flag = false;

		while (!flag)
		{
			cout << "������� ����� ��������: ";
			cin >> menuNumErrorStr;

			try
			{
				menuNum = stoi(menuNumErrorStr);
			}
			catch (...)
			{
				SetConsoleTextAttribute(hConsole, (WORD)((Red << 4) | Black));
				cout << "\n������ �����, ������ �� ���� �������� �������! ��������� ����...\n" << endl;
				SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | White));
				flag = false;
				continue;
			}

			flag = true;
		}

		return menuNum;
	}

	void ChangeInterfaceColor() {
		bool flag = false;

		while (!flag) {
			system("cls");
			cout << "���� ��������� ����������:" << endl;
			cout << "1) ����������� ��������� VS 2019" << endl;
			cout << "2) ��������" << endl;
			cout << "3) ����� ������" << endl;
			cout << "4) ������� ����������� ��������� ����" << endl;
			cout << "5) ����� � ������� ����" << endl;
			cout << "\n";
				
			int colorMenuNum = CheckCorrectMenuNum();
			cout << "\n";

			switch (colorMenuNum) {
			case 1: {

				system("color 07");

				break;
			}
			case 2: {

				system("color F0");

				break;
			}
			case 3: {

				system("color 02");

				break;
			}
			case 4: {

				system("color 0F");

				break;
			}
			case 5: {

				flag = true;
				break;
			}
			default: {
				if (colorMenuNum < 0) {
					cout << "����� �������� �� ����� ���� �������������! ��������� ��� ���...\n\n" << endl;
				}
				else if (colorMenuNum == 0)
				{
					cout << "����� �������� �� ����� ���� ������ ����! ��������� ��� ���...\n\n" << endl;
				}
				else
				{
					cout << "�������� ��� ����� ������ �� �������! ��������� ��� ���...\n\n" << endl;
				}
				break;
			}
			}

		}
	}

	void SortMenu()
	{
		bool menuNum = true;

		while (menuNum)
		{
			cout << "1) ����������� �������� �� ������� �������� [�� �����������]" << endl;
			cout << "2) ����������� �������� �� ������� �������� [�� ��������]" << endl;
			cout << "3) �����" << endl;
			int menuNumber = CheckCorrectMenuNum();
			system("cls");
			switch (menuNumber)
			{
			case 1: {
				actionSort.SortPlantsAscending();

				cout << "������� ��������������!" << endl;

				break;
			}
			case 2: {
				actionSort.SortPlantsDescending();

				cout << "������� ��������������!" << endl;

				break;
			}
			case 3: {
				return;
			}
			default: {

				if (menuNum < 0) {
					cout << "����� �������� �� ����� ���� �������������! ��������� ��� ���...\n\n" << endl;
				}
				else if (menuNum == 0)
				{
					cout << "����� �������� �� ����� ���� ������ ����! ��������� ��� ���...\n\n" << endl;
				}
				else
				{
					cout << "�������� ��� ����� ������ �� �������! ��������� ��� ���...\n\n" << endl;
				}

				system("color 0F");
				break;
			}
			}
		}


	}
};

