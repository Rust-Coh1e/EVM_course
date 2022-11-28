#pragma once
#include "tags.h"
#include "libs.h"
#include "Processor.h"
class MemoryCell
{
private:
	int	status;
public:
	int Give_data();
	int Show_status();
	void Set_data();
	void Set_status();
};

