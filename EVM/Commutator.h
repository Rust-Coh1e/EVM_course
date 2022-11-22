#pragma once
#include "tags.h"
#include "libs.h"
#include "MemoryCell.h"
class Commutator
{
private:
	int status[3];

public:
	int Check_status(int);
	int Ask_Memory_Cell(int);
};

