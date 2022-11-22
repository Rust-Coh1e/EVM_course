#pragma once
#include "tags.h"
#include "libs.h"
#include "Processor.h"
class MemoryCell
{
private:
	int	status;
public:
	void Give_data(int & dur);
	int Show_status();
	void Set_data();
	void Set_status();
};

