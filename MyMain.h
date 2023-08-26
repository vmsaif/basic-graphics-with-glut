#pragma once

#include "Program1.cpp"
#include "Program2.cpp"
#include "Program3.cpp"

int main(int argc, char** argv) {
	
	// ask user to select a program
	int programNumber = 0;
	std::cout << "Please select a program to run: " << std::endl;
	std::cout << "1. Program 1" << std::endl;
	std::cout << "2. Program 2" << std::endl;
	std::cout << "3. Program 3" << std::endl;
	std::cin >> programNumber;

	// run the selected program
	switch (programNumber) {
		case 1:
			Program1::main(argc, argv);
			break;
		case 2:
			Program2::main(argc, argv);
			break;
		case 3:
			Program3::main(argc, argv);
			break;
	}
	
	return EXIT_SUCCESS;
}


