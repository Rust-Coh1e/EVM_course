#pragma once
#include "tags.h"
#include "libs.h"
#include "MemoryCell.h"
class Commutator
{
private:
	int status[NUM_OF_PROC];

public:
	Commutator() {
		for (int i = 0; i < NUM_OF_PROC; i++)
			status[i] = IS_NOT_USED;
	}

	int CheckStatus(int);
	void SetStatus(int, int);

	
};

