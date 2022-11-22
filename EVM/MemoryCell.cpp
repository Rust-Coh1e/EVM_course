#include "MemoryCell.h"


void MemoryCell::Give_data(int & dur) {
	std::cout << "The data was given" << std::endl;
	dur += GIVING_MEMORY_TIME_DURATION;
}