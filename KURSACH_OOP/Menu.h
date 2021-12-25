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

		cout << "Добро пожаловать в меню! Выберите действие!\n\n";

		while (true) {
			cout << "1) Посадить в оранжерею растение" << endl;
			cout << "2) Показать список рассады" << endl;
			cout << "3) Сортировать список рассады" << endl;
			cout << "4) Выкопать растение из оранжереи" << endl;
			cout << "Файловая часть" << endl;
			cout << "5) Прочитайть файл" << endl;
			cout << "6) Сохранить файл" << endl;
			cout << "Тех. параметры" << endl;
			cout << "7) Настройка цветов акцента (BETA);" << endl;
			cout << "0) Выйти;" << endl;	

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

				cout << "Файл успешно прочитан!\n" << endl;

				break;
			}
			case 6: {
				actionFile.WriteFiles();

				cout << "Файл успешно сохранён!\n" << endl;

				break;
			}
			case 7: {
				ChangeInterfaceColor();

				break;
			}
			case 0: {
				cout << "Производится выход...\n\n\n";
				return;
			}
			default: {
				
				if (menuNum < 0) {					
					cout << "Номер действия не может быть отрицательным! Повторите ещё раз...\n\n" << endl;							
				}
				else if (menuNum == 0)
				{	
					cout << "Номер действия не может быть равным нулю! Повторите ещё раз...\n\n" << endl;
				}
				else
				{		
					cout << "Действия под таким числом не имеется! Повторите ещё раз...\n\n" << endl;	
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
			cout << "Введите номер действия: ";
			cin >> menuNumErrorStr;

			try
			{
				menuNum = stoi(menuNumErrorStr);
			}
			catch (...)
			{
				SetConsoleTextAttribute(hConsole, (WORD)((Red << 4) | Black));
				cout << "\nОшибка ввода, номера из меню являются числами! Повторите ввод...\n" << endl;
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
			cout << "Меню установки интерфейса:" << endl;
			cout << "1) Стандратный интерфейс VS 2019" << endl;
			cout << "2) Инверсия" << endl;
			cout << "3) Режим Хакера" << endl;
			cout << "4) Вернуть стандратный интерфейс игры" << endl;
			cout << "5) Выйти в главное меню" << endl;
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
					cout << "Номер действия не может быть отрицательным! Повторите ещё раз...\n\n" << endl;
				}
				else if (colorMenuNum == 0)
				{
					cout << "Номер действия не может быть равным нулю! Повторите ещё раз...\n\n" << endl;
				}
				else
				{
					cout << "Действия под таким числом не имеется! Повторите ещё раз...\n\n" << endl;
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
			cout << "1) Сортировать растения по периоду цветения [по возрастанию]" << endl;
			cout << "2) Сортировать растения по периоду цветения [по убыванию]" << endl;
			cout << "3) Назад" << endl;
			int menuNumber = CheckCorrectMenuNum();
			system("cls");
			switch (menuNumber)
			{
			case 1: {
				actionSort.SortPlantsAscending();

				cout << "Успешно отсартированно!" << endl;

				break;
			}
			case 2: {
				actionSort.SortPlantsDescending();

				cout << "Успешно отсартированно!" << endl;

				break;
			}
			case 3: {
				return;
			}
			default: {

				if (menuNum < 0) {
					cout << "Номер действия не может быть отрицательным! Повторите ещё раз...\n\n" << endl;
				}
				else if (menuNum == 0)
				{
					cout << "Номер действия не может быть равным нулю! Повторите ещё раз...\n\n" << endl;
				}
				else
				{
					cout << "Действия под таким числом не имеется! Повторите ещё раз...\n\n" << endl;
				}

				system("color 0F");
				break;
			}
			}
		}


	}
};

