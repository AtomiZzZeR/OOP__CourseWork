#pragma once

#include <iostream>
#include <string.h>
#include "CharacterPlant.h"
#include "Period.h"

using namespace std;

class Plant
{
private:
	CharacterPlant character;
	Period period;

public:
	Plant() {

	}

	CharacterPlant GetCharacter() {
		return character;
	}

	Period GetPeriod() {
		return period;
	}

	void SetPlant(CharacterPlant character, Period period) {
		this->character = character;
		this->period = period;
	}
};

