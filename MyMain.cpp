/*
	Author: Saif Mahmud
    Date : 1 / 25 / 2023

	Descroption: Main file that runs the program selected by the user.
*/

#include "Program1.cpp"
#include "Program2.cpp"
#include "Program3.cpp"
#include "Program4.cpp"

int main(int argc, char** argv) {

	// ask user to select a program
	int programNumber = 0;
	std::cout << "Please select a program to run: " << std::endl;
	std::cout << "1. Program 1: Using Anti Aliasing Technique" << std::endl;
	std::cout << "2. Program 2: Translating and Rotating" << std::endl;
	std::cout << "3. Program 3: Color Gradient" << std::endl;
	std::cout << "4. Program 4: Houses with Translation, Scaling, and Rotation to Transformormation" << std::endl;


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
	case 4:
		Program4::main(argc, argv);
		break;
	}

	return EXIT_SUCCESS;
}



