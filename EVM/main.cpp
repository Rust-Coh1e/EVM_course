#include "scheme1.h"
#include "scheme2.h"

int main() {
	scheme1 scheme_BUS;
	scheme2 scheme_COM;
	
	scheme_BUS.Fill_COMMANDS_ARRAY();
	scheme_BUS.Perform_the_commands();

	std::cout << std::endl << "****************" << std::endl;
	scheme_COM.Coppy_COMMANDS_ARRAY(scheme_BUS.COMMANDS_ARRAY);

	scheme_COM.Perform_the_commands();


	//this->N = THE_AMOUNT_OF_THE_PROCMC;
	//this->commands_amount = THE_AMOUNT_OF_COMMANDS;


	/*
	int** COMMANDS_ARRAY = new int* [THE_AMOUNT_OF_THE_PROCMC];

	for (int i = 0; i < THE_AMOUNT_OF_THE_PROCMC; i++)
	{
		COMMANDS_ARRAY[i] = new int[THE_AMOUNT_OF_COMMANDS];
	}
	for (int i = 0; i < THE_AMOUNT_OF_THE_PROCMC; i++)
	{
		delete[] COMMANDS_ARRAY[i];
	}
	delete[] COMMANDS_ARRAY;

	*/
}