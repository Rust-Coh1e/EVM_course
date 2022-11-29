#pragma once
#include "tags.h"
#include "libs.h"
#include "MemoryCell.h"
class Commutator
{
private:
	int status[THE_AMOUNT_OF_THE_PROCMC];

public:
	Commutator() {
		for (int i = 0; i < THE_AMOUNT_OF_THE_PROCMC; i++)
			status[i] = IS_NOT_USED;
	}

	int CheckStatus(int);
	void SetStatus(int, int);

	
};

