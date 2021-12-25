#pragma once

#include <iostream>
#include <string.h>

using namespace std;

class NamePlant
{
protected:
	char namePlant[100];

public:
	string GetNamePlant() {
		return namePlant;
	}
};

