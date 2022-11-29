#pragma once
#include "tags.h"
#include "libs.h"
#include "Bus.h"
#include "Processor.h"
#include "Commutator.h"
#include "MemoryCell.h"


class scheme2
{
	Processor PROC[THE_AMOUNT_OF_THE_PROCMC];
	MemoryCell MC[THE_AMOUNT_OF_THE_PROCMC];
	Commutator COM;

	//int time_cons;

	int N;
	int commands_amount;
	int com_no_data, com_data, com_same_num, com_not_same_num;
public:
	int** COMMANDS_ARRAY;
	scheme2() {
		this->N = THE_AMOUNT_OF_THE_PROCMC;
		COMMANDS_ARRAY = new int* [this->N];
		this->commands_amount = THE_AMOUNT_OF_COMMANDS;
		for (int i = 0; i < this->N; i++)
		{
			COMMANDS_ARRAY[i] = new int[commands_amount];
		}
	}

	~scheme2() {
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

