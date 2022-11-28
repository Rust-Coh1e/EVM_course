#include "Processor.h"


void Ask_for_data() {

}


int Processor::Perform_calculation(int COM) {
	
	if (COM == COMMAND_WITH_NO_MEMORY_USE) {
		if(SHOW_HIDDEN_STAF) std::cout << "COMMAND WITH NO DATA WAS EXECUTED" << std::endl;;
		return NO_MEMORY_TIME_DURATION;
	}
	else if (COM == COMMAND_WITH_MEMORY_USE) {
		if (SHOW_HIDDEN_STAF) std::cout << "COMMAND WITH DATA WAS ASKED" << std::endl;;
		return ZERO_TIME_DURATION;
	}
	else if (COM == COMMAND_WITH_MEMORY_USE___WAS_GIVEN) {
		if (SHOW_HIDDEN_STAF) std::cout << "COMMAND WITH DATA WAS EXECUTED" << std::endl;;
		return ZERO_TIME_DURATION;
	}
	else std::cout << "ERROR with command performing";
}