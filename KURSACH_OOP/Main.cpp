#include <iostream>
#include <string>
#include "Menu.h"
#include <windows.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Menu mainMenu;

	mainMenu.MainMenu();
	return 0;
}