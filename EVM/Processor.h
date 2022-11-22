#pragma once
#include "tags.h"
#include "libs.h"

class Processor
{
private:
	//int Comand_no_data_needed=0;	// the amount of the commands that do not need
	//int Comand_data_needed=0;		// the amount of the commands that need it
public:
	void Ask_for_data();
	void Perform_calculation(int COM, int& dur);
};

