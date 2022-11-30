#include "Processor.h"


void Ask_for_data() {

}


int Processor::Perform_calculation(int COM) {
	
	if (COM == CMD_NO_MEM) {
		if(INFORM_OUTPUT) std::cout << "Cmd without data was called" << std::endl;;
		return TIME_NO_MEM;
	}
	else if (COM == CMD_REQ_MEM) {
		if (INFORM_OUTPUT) std::cout << "Cmd with data was called" << std::endl;;
		return ZERO;
	}
	else if (COM == CMD_MEM_G) {
		if (INFORM_OUTPUT) std::cout << "Cmd with data was executed" << std::endl;;
		return ZERO;
	}
	
}