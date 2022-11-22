#include "scheme1.h"
void scheme1::Perform_the_commands() {
	//std::cout << this->BUS.CheckIsUsed();
}

void scheme1::Fill_COMMANDS_ARRAY() {
	std::cout << commands_amount << std::endl;
	this->com_no_data = this->commands_amount * 0.85;
	this->com_data = commands_amount - (this->com_no_data);

	std::cout << com_no_data << " " << com_data << std::endl;

	this->com_same_num = com_data * 0.80;
	this->com_not_same_num = com_data - this->com_same_num;
	if (this->com_not_same_num %2 == 1) {
		com_not_same_num--;
		com_same_num++;
	}
	com_not_same_num = com_not_same_num / 2;
	std::cout << com_same_num << " " << com_not_same_num << " " << com_not_same_num << std::endl;


	///////////////////////////////////
	for (int i = 0; i < this->N; i++) {
		for (int j = 0; j < commands_amount; j++) {
			this->COMMANDS_ARRAY[i][j]=-5;
		}
	}

	int helper_for_rnd;
	int ind_h1 = 1;
	int ind_h2 = 2;

	for (int i = 0; i < this->N; i++) {
		
		for (int j = 0; j < this->com_no_data; j++) {
			helper_for_rnd = rand() % commands_amount;
			while(this->COMMANDS_ARRAY[i][helper_for_rnd] ==0) {
				helper_for_rnd = rand() % commands_amount;
			}
			(this->COMMANDS_ARRAY[i][helper_for_rnd]) = 0;
			//std::cout << i << " " << j << std::endl;
		}
		
		for (int j = 0; j < this->com_same_num; j++) {
			helper_for_rnd = rand() % commands_amount;
			while ((this->COMMANDS_ARRAY[i][helper_for_rnd] == 0) ||
				(this->COMMANDS_ARRAY[i][helper_for_rnd]) == (10+(i+1))) {
				helper_for_rnd = rand() % commands_amount;
			}
			(this->COMMANDS_ARRAY[i][helper_for_rnd]) = 10+ (i + 1);
		}

		for (int j = 0; j < this->com_not_same_num; j++) {
			helper_for_rnd = rand() % commands_amount;
			while (
				(this->COMMANDS_ARRAY[i][helper_for_rnd] == 0) ||
				(this->COMMANDS_ARRAY[i][helper_for_rnd] == 10 + (i + 1))   ||
				(this->COMMANDS_ARRAY[i][helper_for_rnd] == 10 + (i + 1+ ind_h1))
				) {
				helper_for_rnd = rand() % commands_amount;
			}
			(this->COMMANDS_ARRAY[i][helper_for_rnd]) = 10 + (i + 1 + ind_h1);
		}

		for (int j = 0; j < this->com_not_same_num; j++) {
			helper_for_rnd = rand() % commands_amount;
			while (
				(this->COMMANDS_ARRAY[i][helper_for_rnd] == 0) ||
				(this->COMMANDS_ARRAY[i][helper_for_rnd] == 10 + (i + 1)) ||
				(this->COMMANDS_ARRAY[i][helper_for_rnd] == 10 + (i + 1 + ind_h1)) ||
				(this->COMMANDS_ARRAY[i][helper_for_rnd] == 10 + (i + 1  + ind_h2))
				) {
				helper_for_rnd = rand() % commands_amount;
			}
			(this->COMMANDS_ARRAY[i][helper_for_rnd]) = 10 + (i + 1 + ind_h2);
		}

		if (i == 0) ind_h1 = (-1);
		if (i == 1) ind_h2 = (-2);
	}


	
	for (int i = 0; i < this->N; i++) {
		for (int j = 0; j < commands_amount; j++) {
			std::cout << this->COMMANDS_ARRAY[i][j] << " ";
		}
		std::cout << std::endl;
	}
}