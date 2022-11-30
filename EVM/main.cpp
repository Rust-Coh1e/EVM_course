#include "first.h"
#include "second.h"



int main() {

	int THE_AMOUNT_OF_COMMANDS;
	std::cout << "Enter the number of commands" << std::endl << "->";
	std::cin >> THE_AMOUNT_OF_COMMANDS;


	first scheme_BUS = first(THE_AMOUNT_OF_COMMANDS);
	second scheme_COM = second(THE_AMOUNT_OF_COMMANDS);
	
	scheme_BUS.Fill_COMMANDS_ARRAY();
	scheme_BUS.Perform_the_commands();

	std::cout << std::endl << "****************" << std::endl;
	scheme_COM.Coppy_COMMANDS_ARRAY(scheme_BUS.COMMANDS_ARRAY);

	scheme_COM.Perform_the_commands();


}