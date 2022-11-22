#include "Processor.h"


void Ask_for_data() {

}


void Processor::Perform_calculation(int COM, int & dur) {
	if (COM == COMMAND_WITH_NO_MEMORY_USE) {
		dur++;
	}
	else if (COM == COMMAND_WITH_MEMORY_USE) {
		std::cout << "COMMAND WITH NO DATA WAS ASKED" << std::endl;;
	}
	else std::cout << "ERROR with command performing";
}