#include "first.h"


void first::Fill_COMMANDS_ARRAY() {
	if (INFORM_OUTPUT) std::cout << "the amounts of commands " << NUM_of_CMD << std::endl;
	this->com_no_data = this->NUM_of_CMD * 0.85;
	this->com_data = NUM_of_CMD - (this->com_no_data);

	if (INFORM_OUTPUT_PLUS) std::cout << com_no_data << " " << com_data << std::endl;

	this->com_same_num = com_data * 0.80;
	this->com_not_same_num = com_data - this->com_same_num;
	if (this->com_not_same_num %2 == 1) {
		com_not_same_num--;
		com_same_num++;
	}
	com_not_same_num = com_not_same_num / 2;
	if (INFORM_OUTPUT_PLUS) std::cout << com_same_num << " " << com_not_same_num << " " << com_not_same_num << std::endl;


	///////////////////////////////////
	for (int i = 0; i < this->N; i++) {
		for (int j = 0; j < NUM_of_CMD; j++) {
			this->COMMANDS_ARRAY[i][j]=-5;
		}
	}

	int helper_for_rnd;
	int ind_h1 = 1;
	int ind_h2 = 2;

	for (int i = 0; i < this->N; i++) {
		
		for (int j = 0; j < this->com_no_data; j++) {
			helper_for_rnd = rand() % NUM_of_CMD;
			while(this->COMMANDS_ARRAY[i][helper_for_rnd] ==0) {
				helper_for_rnd = rand() % NUM_of_CMD;
			}
			(this->COMMANDS_ARRAY[i][helper_for_rnd]) = 0;
			//std::cout << i << " " << j << std::endl;
		}
		
		for (int j = 0; j < this->com_same_num; j++) {
			helper_for_rnd = rand() % NUM_of_CMD;
			while ((this->COMMANDS_ARRAY[i][helper_for_rnd] == 0) ||
				(this->COMMANDS_ARRAY[i][helper_for_rnd]) == (10+(i+1))) {
				helper_for_rnd = rand() % NUM_of_CMD;
			}
			(this->COMMANDS_ARRAY[i][helper_for_rnd]) = 10+ (i + 1);
		}

		for (int j = 0; j < this->com_not_same_num; j++) {
			helper_for_rnd = rand() % NUM_of_CMD;
			while (
				(this->COMMANDS_ARRAY[i][helper_for_rnd] == 0) ||
				(this->COMMANDS_ARRAY[i][helper_for_rnd] == 10 + (i + 1))   ||
				(this->COMMANDS_ARRAY[i][helper_for_rnd] == 10 + (i + 1+ ind_h1))

		) {
				helper_for_rnd = rand() % NUM_of_CMD;
			}
			(this->COMMANDS_ARRAY[i][helper_for_rnd]) = 10 + (i + 1);
		}

		for (int j = 0; j < this->com_not_same_num; j++) {
			helper_for_rnd = rand() % NUM_of_CMD;
			while (
				(this->COMMANDS_ARRAY[i][helper_for_rnd] == 0) ||
				(this->COMMANDS_ARRAY[i][helper_for_rnd] == 10 + (i + 1)) ||
				(this->COMMANDS_ARRAY[i][helper_for_rnd] == 10 + (i + 1 + ind_h1)) ||
				(this->COMMANDS_ARRAY[i][helper_for_rnd] == 10 + (i + 1  + ind_h2))
				) {
				helper_for_rnd = rand() % NUM_of_CMD;
			}
			(this->COMMANDS_ARRAY[i][helper_for_rnd]) = 10 + (i + 1 + ind_h2);
		}

		if (i == 0) {
			ind_h1 = (-1); ind_h2 = (-1);
		}
		if (i == 1) ind_h2 = (-2);
	}
	
}


void first::Perform_the_commands() {
	if (INFORM_OUTPUT) {
		std::cout << "The massiv of tasks" << std::endl;
		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < NUM_of_CMD; j++) {
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



	int is_the_task_done_first = INDEFINITE;
	int is_the_task_done_second = INDEFINITE;
	int is_the_task_done_third = INDEFINITE;

	int extra_waiting_time = 0;
	int max_time = 0;
	int time_total = 0;

	int is_used_by_me = 0;
	/*
	is_used_by_me helps to emitate the paral of the commands
	basically tells that i am using this shiiittt
	0 - is not used by anyone, but will not be used (cause we'll just use IS_NOT_USED)
	1 - first proc
	2 - second proc
	3 - third proc
	*/

	for (int i = 0; i < this->NUM_of_CMD; i++) {

		if (INFORM_OUTPUT_PLUS) std::cout << "The cycle number " << i+1  << std::endl;
		extra_waiting_time = 0;
		
		if (this->COMMANDS_ARRAY[0][i] == 00)
		{
			time_used_by_first = this->PROC[0].Perform_calculation(CMD_NO_MEM);
			is_the_task_done_first = YES;
		}	else is_the_task_done_first = NO;
		if (this->COMMANDS_ARRAY[1][i] == 00)
		{
			time_used_by_second = this->PROC[1].Perform_calculation(CMD_NO_MEM);
			is_the_task_done_second = YES;
		}	else is_the_task_done_second = NO;
		if (this->COMMANDS_ARRAY[2][i] == 00)
		{
			time_used_by_third = this->PROC[2].Perform_calculation(CMD_NO_MEM);
			is_the_task_done_third = YES;
		}	else is_the_task_done_third = NO;

		bool are_they_all_done = is_the_task_done_first && is_the_task_done_second && is_the_task_done_third;

		while (!are_they_all_done) {

			if ((this->COMMANDS_ARRAY[0][i] / 10 == 1) && (!is_the_task_done_first))
			{
				if (!(this->BUS.CheckIsUsed())) {
					this->BUS.SetStatus(IS_USED);
					is_used_by_me = 1;
					time_used_by_first = this->PROC[0].Perform_calculation(CMD_REQ_MEM);
					
				}
				else 
					if (is_used_by_me == 1) {
						time_used_by_first +=	
							this->MC[0].Give_data() +
							this->PROC[0].Perform_calculation(CMD_MEM_G);
						extra_waiting_time += TIME_MEM;
						is_the_task_done_first = YES;
						this->BUS.SetStatus(IS_NOT_USED);
						is_used_by_me = 0;
					}

			}

			if (this->COMMANDS_ARRAY[1][i] / 10 == 1 && (!is_the_task_done_second))
			{
				if (!(this->BUS.CheckIsUsed())) {
					this->BUS.SetStatus(IS_USED);
					is_used_by_me = 2;
					time_used_by_second = this->PROC[1].Perform_calculation(CMD_REQ_MEM);
					
				}
				else
					if (is_used_by_me == 2) {
						time_used_by_second +=
							this->MC[1].Give_data() +
							this->PROC[1].Perform_calculation(CMD_MEM_G);
						time_used_by_second += extra_waiting_time;// - Z_T_D caus with staf we did upper we add it two times - kostil koroche
						extra_waiting_time += TIME_MEM;
						is_the_task_done_second = YES;
						this->BUS.SetStatus(IS_NOT_USED);
						is_used_by_me = 0;
					}
			}

			if (this->COMMANDS_ARRAY[2][i] / 10 == 1 && (!is_the_task_done_third))
			{
				if (!(this->BUS.CheckIsUsed())) {
					this->BUS.SetStatus(IS_USED);
					is_used_by_me = 3;
					time_used_by_third = this->PROC[2].Perform_calculation(CMD_REQ_MEM);
					
				}
				else
					if (is_used_by_me == 3) {
						time_used_by_third +=
							this->MC[2].Give_data() +
							this->PROC[2].Perform_calculation(CMD_MEM_G);
						time_used_by_third += extra_waiting_time; // - Z_T_D caus with staf we did upper we add it two times - kostil koroche
						extra_waiting_time += TIME_MEM;
						is_the_task_done_third = YES;
						this->BUS.SetStatus(IS_NOT_USED);
						is_used_by_me = 0;
					}
			}
			are_they_all_done = is_the_task_done_first && is_the_task_done_second && is_the_task_done_third;
		}

		max_time = std::max(std::max(time_used_by_first, time_used_by_second), time_used_by_third);



		if (INFORM_OUTPUT_PLUS) {
			std::cout << time_used_by_first << " " << time_used_by_second << " "
				<< time_used_by_third << std::endl;
			std::cout << max_time << std::endl;
		}

		time_total += max_time;

	}

	std::cout << std::endl << "All the tasks were complited under " << time_total << " cu's"
		<< std::endl << std::endl;

}

void first::Coppy_COMMANDS_ARRAY(int** copy) {
	for (int i = 0; i < this->N; i++) {
		for (int j = 0; j < NUM_of_CMD; j++) {
			this->COMMANDS_ARRAY[i][j] = copy[i][j];
		}
	}

	if (INFORM_OUTPUT_PLUS) {
		std::cout << "The massiv of tasks (copied)" << std::endl;
		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < NUM_of_CMD; j++) {
				std::cout << this->COMMANDS_ARRAY[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
}
