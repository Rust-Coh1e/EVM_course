#include "Bus.h"

int Bus::CheckIsUsed() {
	return this->status;
}

void Bus::SetStatus(int sts) {
	if (sts == IS_USED) this->status = IS_USED;
	else if (sts == IS_NOT_USED) this->status = IS_NOT_USED;
	else std::cout << "ERROR TOTAL FLOP, wrong status" << std::endl;
}