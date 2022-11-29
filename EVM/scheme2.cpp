#include "scheme2.h"


void scheme2::Fill_COMMANDS_ARRAY() {
	if (SHOW_HIDDEN_STAF) std::cout << "the amounts of commands " << commands_amount << std::endl;
	this->com_no_data = this->commands_amount * 0.85;
	this->com_data = commands_amount - (this->com_no_data);

	if (SHOW_HIDDEN_STAF_SUPREME) std::cout << com_no_data << " " << com_data << std::endl;

	this->com_same_num = com_data * 0.80;
	this->com_not_same_num = com_data - this->com_same_num;
	if (this->com_not_same_num % 2 == 1) {
		com_not_same_num--;
		com_same_num++;
	}
	com_not_same_num = com_not_same_num / 2;
	if (SHOW_HIDDEN_STAF_SUPREME) std::cout << com_same_num << " " << com_not_same_num << " " << com_not_same_num << std::endl;


	///////////////////////////////////
	for (int i = 0; i < this->N; i++) {
		for (int j = 0; j < commands_amount; j++) {
			this->COMMANDS_ARRAY[i][j] = -5;
		}
	}

	int helper_for_rnd;
	int ind_h1 = 1;
	int ind_h2 = 2;

	for (int i = 0; i < this->N; i++) {

		for (int j = 0; j < this->com_no_data; j++) {
			helper_for_rnd = rand() % commands_amount;
			while (this->COMMANDS_ARRAY[i][helper_for_rnd] == 0) {
				helper_for_rnd = rand() % commands_amount;
			}
			(this->COMMANDS_ARRAY[i][helper_for_rnd]) = 0;
			//std::cout << i << " " << j << std::endl;
		}

		for (int j = 0; j < this->com_same_num; j++) {
			helper_for_rnd = rand() % commands_amount;
			while ((this->COMMANDS_ARRAY[i][helper_for_rnd] == 0) ||
				(this->COMMANDS_ARRAY[i][helper_for_rnd]) == (10 + (i + 1))) {
				helper_for_rnd = rand() % commands_amount;
			}
			(this->COMMANDS_ARRAY[i][helper_for_rnd]) = 10 + (i + 1);
		}

		for (int j = 0; j < this->com_not_same_num; j++) {
			helper_for_rnd = rand() % commands_amount;
			while (
				(this->COMMANDS_ARRAY[i][helper_for_rnd] == 0) ||
				(this->COMMANDS_ARRAY[i][helper_for_rnd] == 10 + (i + 1)) ||
				(this->COMMANDS_ARRAY[i][helper_for_rnd] == 10 + (i + 1 + ind_h1))
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
				(this->COMMANDS_ARRAY[i][helper_for_rnd] == 10 + (i + 1 + ind_h2))
				) {
				helper_for_rnd = rand() % commands_amount;
			}
			(this->COMMANDS_ARRAY[i][helper_for_rnd]) = 10 + (i + 1 + ind_h2);
		}

		if (i == 0) ind_h1 = (-1);
		if (i == 1) ind_h2 = (-2);
	}



	/////////////////__Block_to_chek_this_shit///////////////////
	/*
	for (int i = 0; i < this->N; i++) {
		for (int j = 0; j < commands_amount; j++) this->COMMANDS_ARRAY[i][j] = 00;
	}

	this->COMMANDS_ARRAY[0][0] = 11;
	this->COMMANDS_ARRAY[1][0] = 12;
	this->COMMANDS_ARRAY[2][0] = 13;

	this->COMMANDS_ARRAY[0][1] = 11;
	this->COMMANDS_ARRAY[1][1] = 00;
	this->COMMANDS_ARRAY[2][1] = 11;

	this->COMMANDS_ARRAY[0][2] = 11;
	this->COMMANDS_ARRAY[1][2] = 12;
	this->COMMANDS_ARRAY[2][2] = 12;
	*/
	/////////////////////////////////////////////////////////////


}


void scheme2::Coppy_COMMANDS_ARRAY(int** copy){
		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < commands_amount; j++) {
				this->COMMANDS_ARRAY[i][j] = copy[i][j];
			}
		}

	if (SHOW_HIDDEN_STAF_SUPREME) {
		std::cout << "The massiv of tasks (copied)" << std::endl;
		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < commands_amount; j++) {
				std::cout <<this->COMMANDS_ARRAY[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
}

void scheme2::Perform_the_commands() {
	if (SHOW_HIDDEN_STAF) {
		std::cout << "The massiv of tasks" << std::endl;
		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < commands_amount; j++) {
				std::cout << this->COMMANDS_ARRAY[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}

	std::cout << std::endl;
	std::cout << std::endl;

	int time_used_by_first = -1;
	int time_used_by_second = -1;
	int time_used_by_third = -1;



	int is_the_task_done_first = IT_WILL_BE_BAD;
	int is_the_task_done_second = IT_WILL_BE_BAD;
	int is_the_task_done_third = IT_WILL_BE_BAD;

	int extra_waiting_time = 0;
	int max_time = 0;
	int time_total = 0;

	int is_used_by_me[3] = { 0,0,0 };

	int is_it_odd_takt = 0;

	int fck[3] = { 0,0,0 };
	/*
	is_used_by_me helps to emitate the paral of the commands
	basically tells that i am using this shiiittt
	0 - is not used by anyone, but will not be used (cause we'll just use IS_NOT_USED)
	1 - first proc
	2 - second proc
	3 - third proc
	*/

	for (int i = 0; i < this->commands_amount; i++) {

		if (SHOW_HIDDEN_STAF_SUPREME) std::cout << "The cycle number " << i << "*************************" << std::endl;

		if (this->COMMANDS_ARRAY[0][i] == 00)
		{
			time_used_by_first = this->PROC[0].Perform_calculation(COMMAND_WITH_NO_MEMORY_USE);
			is_the_task_done_first = YES;
		}
		else is_the_task_done_first = NO;
		if (this->COMMANDS_ARRAY[1][i] == 00)
		{
			time_used_by_second = this->PROC[1].Perform_calculation(COMMAND_WITH_NO_MEMORY_USE);
			is_the_task_done_second = YES;
		}
		else is_the_task_done_second = NO;
		if (this->COMMANDS_ARRAY[2][i] == 00)
		{
			time_used_by_third = this->PROC[2].Perform_calculation(COMMAND_WITH_NO_MEMORY_USE);
			is_the_task_done_third = YES;
		}
		else is_the_task_done_third = NO;

		bool are_they_all_done = is_the_task_done_first && is_the_task_done_second && is_the_task_done_third;

		extra_waiting_time = 0;
		is_it_odd_takt = 0;

		

		while (!are_they_all_done) {
			if (this->COMMANDS_ARRAY[0][i] / 10 == 1)
			{
				for (int indexMC = 0; indexMC < 3; indexMC++) {
					if (this->COMMANDS_ARRAY[0][i] % 10 == (indexMC+1) && (!is_the_task_done_first)) {
						if (SHOW_HIDDEN_STAF_SUPREME) std::cout << indexMC + 1
							<< " MC was tried to get by 1" << std::endl;
						if (!(this->COM.CheckStatus(indexMC))) {
							if (is_it_odd_takt % 2 == 0) {
								if (SHOW_HIDDEN_STAF_SUPREME) std::cout << indexMC + 1 << " MC was open to get" << std::endl;
								this->COM.SetStatus(indexMC, IS_USED);
								fck[0] = 0;
								is_used_by_me[indexMC] = 1;
								time_used_by_first = this->PROC[0].Perform_calculation(COMMAND_WITH_MEMORY_USE);
								extra_waiting_time += ZERO_TIME_DURATION;
							}
						}
						else
							if (is_used_by_me[indexMC] == 1) {
								time_used_by_first +=
									this->MC[indexMC].Give_data() +
									this->PROC[0].Perform_calculation(COMMAND_WITH_MEMORY_USE___WAS_GIVEN);
								time_used_by_first += extra_waiting_time;  // no - Z_T_D caus with staf we did upper we add it two times - kostil koroche
								//extra_waiting_time += GIVING_MEMORY_TIME_DURATION + ZERO_TIME_DURATION;
								is_the_task_done_first = YES;
								this->COM.SetStatus(indexMC, IS_NOT_USED);
								//fck[0] = indexMC+1;
								is_used_by_me[indexMC] = 0;
							}
					}
				}
			}

			if (this->COMMANDS_ARRAY[1][i] / 10 == 1 && (!is_the_task_done_second))
			{
				for (int indexMC = 0; indexMC < 3; indexMC++) {
					if (this->COMMANDS_ARRAY[1][i] % 10 == (indexMC + 1)) {
						if (SHOW_HIDDEN_STAF_SUPREME) std::cout << indexMC + 1
							<< " MC was tried to get by 2"  << std::endl;
						if (!(this->COM.CheckStatus(indexMC))) {
							if (is_it_odd_takt % 2 == 0) {
								if (SHOW_HIDDEN_STAF_SUPREME) std::cout << indexMC + 1 << " MC was open to get" << std::endl;
								this->COM.SetStatus(indexMC, IS_USED);
								fck[1] = 0;
								is_used_by_me[indexMC] = 2;
								time_used_by_second = this->PROC[0].Perform_calculation(COMMAND_WITH_MEMORY_USE);
								extra_waiting_time += ZERO_TIME_DURATION;
							}
						}
						else
							if (is_used_by_me[indexMC] == 2 && (!is_the_task_done_second)) {
								time_used_by_second +=
									this->MC[indexMC].Give_data() +
									this->PROC[0].Perform_calculation(COMMAND_WITH_MEMORY_USE___WAS_GIVEN);
								time_used_by_second += extra_waiting_time;  // - no Z_T_D caus with staf we did upper we add it two times - kostil koroche
								//extra_waiting_time += GIVING_MEMORY_TIME_DURATION + ZERO_TIME_DURATION;
								is_the_task_done_second = YES;
								//fck[1] = indexMC+1;
								this->COM.SetStatus(indexMC, IS_NOT_USED);
								is_used_by_me[indexMC] = 0;
							}
					}
				}
			}

			if (this->COMMANDS_ARRAY[2][i] / 10 == 1)
			{
				for (int indexMC = 0; indexMC < 3; indexMC++) {
					if (this->COMMANDS_ARRAY[2][i] % 10 == (indexMC + 1)) {
						if (SHOW_HIDDEN_STAF_SUPREME) std::cout << indexMC + 1
							<< " MC was tried to get by 3" << std::endl;
						if (!(this->COM.CheckStatus(indexMC))) {
							if (is_it_odd_takt % 2 == 0) {
								if (SHOW_HIDDEN_STAF_SUPREME) std::cout << indexMC + 1 << " MC was open to get" << std::endl;
								this->COM.SetStatus(indexMC, IS_USED);
								fck[2] = 0;
								is_used_by_me[indexMC] = 3;
								time_used_by_third = this->PROC[0].Perform_calculation(COMMAND_WITH_MEMORY_USE);
								extra_waiting_time += ZERO_TIME_DURATION;
							}
						}
						else
							if (is_used_by_me[indexMC] == 3 && (!is_the_task_done_third)) {
								time_used_by_third +=
									this->MC[indexMC].Give_data() +
									this->PROC[0].Perform_calculation(COMMAND_WITH_MEMORY_USE___WAS_GIVEN);
								time_used_by_third += extra_waiting_time ;  // no - Z_T_D caus with staf we did upper we add it two times - kostil koroche
								//extra_waiting_time += GIVING_MEMORY_TIME_DURATION + ZERO_TIME_DURATION;
								is_the_task_done_third = YES;
								//fck[2] = indexMC+1;
								this->COM.SetStatus(indexMC, IS_NOT_USED);
								is_used_by_me[indexMC] = 0;
							}
					}
				}
			}































			if(is_it_odd_takt %2 == 1 )
				extra_waiting_time += GIVING_MEMORY_TIME_DURATION + ZERO_TIME_DURATION;
			is_it_odd_takt++;
			are_they_all_done = is_the_task_done_first && is_the_task_done_second && is_the_task_done_third;
		}
	

		max_time = std::max(std::max(time_used_by_first, time_used_by_second), time_used_by_third);



		if (SHOW_HIDDEN_STAF_SUPREME) {
			std::cout << time_used_by_first << " " << time_used_by_second << " "
				<< time_used_by_third << std::endl;
			std::cout << max_time << std::endl;
		}

		time_total += max_time;

	}

	std::cout << std::endl << "All the tasks were complited under " << time_total << " cu's"
		<< std::endl << std::endl;

}