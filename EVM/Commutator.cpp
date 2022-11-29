#include "Commutator.h"

int Commutator::CheckStatus(int id) {
	return this->status[id];
}

void Commutator::SetStatus(int id, int sts) {
	if (sts == IS_USED) this->status[id] = IS_USED;
	else if (sts == IS_NOT_USED) this->status[id] = IS_NOT_USED;
	else std::cout << "ERROR TOTAL FLOP, wrong status" << std::endl;
}
