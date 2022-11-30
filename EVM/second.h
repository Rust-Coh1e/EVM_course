#pragma once
#include "tags.h"
#include "libs.h"
#include "Bus.h"
#include "Processor.h"
#include "Commutator.h"
#include "MemoryCell.h"


class second
{
	Processor PROC[NUM_OF_PROC];
	MemoryCell MC[NUM_OF_PROC];
	Commutator COM;

	//int time_cons;

	int N;
	int NUM_of_CMD;
	int com_no_data, com_data, com_same_num, com_not_same_num;
public:
	int** COMMANDS_ARRAY;
	second(int THE_AMOUNT_OF_COMMANDS) {
		this->N = NUM_OF_PROC;
		COMMANDS_ARRAY = new int* [this->N];
		this->NUM_of_CMD = THE_AMOUNT_OF_COMMANDS;
		for (int i = 0; i < this->N; i++)
		{
			COMMANDS_ARRAY[i] = new int[NUM_of_CMD];
		}
	}

	~second() {
		for (int i = 0; i < this->N; i++)
		{
			delete[] COMMANDS_ARRAY[i];
		}
		delete[] COMMANDS_ARRAY;
	}

	void Fill_COMMANDS_ARRAY();
	void Perform_the_commands();
	void Coppy_COMMANDS_ARRAY(int **);
};

