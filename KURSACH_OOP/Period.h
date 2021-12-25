#pragma once

#include <iostream>
#include <regex>

using namespace std;

class Period
{
private:
	int period = 0;

	int GetCheckPeriod() {
		string h_periodStr;
		int h_period;
		bool flag = false;

		while (!flag) {
			cin >> h_periodStr;

			try
			{
				h_period = stoi(h_periodStr);

				if (h_period < 2 || h_period > 8) {
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

		return h_period;
	}

public:
	void SetPeriod()
	{
		cout << "Период цветения: ";
		period = GetCheckPeriod();
		cout << "\n";
	}

	int GetPeriod2() {
		return period;
	}
};

