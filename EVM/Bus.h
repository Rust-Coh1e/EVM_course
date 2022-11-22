#pragma once
#include "tags.h"
#include "libs.h"
class Bus
{
private:
	int status;
public:
	Bus() {
		this->status = IS_NOT_USED;
	};
	int CheckIsUsed();
	int Ask_Memory_Cell(int);
};

