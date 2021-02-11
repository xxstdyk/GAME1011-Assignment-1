#include "Survey.h"
#include <fstream>
#include <vector>

// you gotta at least let me use it for this it's not even one of the requirements !
std::vector<std::string> first_names;
std::vector<std::string> last_names;

int main() {

	int numParticipants; // put the number of participants in here

	do {
		std::cout << "Welcome." << std::endl;
		std::cout << "How many participants are going to participate in the survey?" << std::endl;
		std::cout << "Note: This program allows a maximum of 500 participants." << std::endl;
		std::cin >> numParticipants;

		if (numParticipants > 500 || numParticipants < 1) {   //Input Validation
			std::cout << "ERROR: The number of participants has to be at least 1 and a maximum of 500." << std::endl;
			Util::PauseClear();
		}

	} while (numParticipants > 500 || numParticipants < 1);  //Repeats while input is invalid


	Util::ClearScreen();

	for (int i = 0; i < numParticipants; ++i) {
		// generate participants & add them to Survey class
	}

	std::ifstream istream;

	// Reading in a list of first names
	istream.open("names.txt");

	if (istream.is_open()) {
		std::string name;
		while (getline(istream, name))
			first_names.push_back(name);

	}
	else
		std::cerr << "Names file not found." << std::endl;

	istream.close();

	// Reading in a list of last names
	istream.open("last-names.txt");

	if (istream.is_open()) {
		std::string lastName;
		while (getline(istream, lastName))
			last_names.push_back(lastName);

	}
	else
		std::cerr << "Last Names file not found." << std::endl;

	istream.close();

	int userInput;
	bool proceed = false;

	do {
		std::cout << "Are you ready to process the servey?" << std::endl;
		std::cout << "[1] Yes\t[2] Exit" << std::endl;

		switch (userInput) {
		case 1:
			proceed = true;
			// process function here
			break;
		case 2:
			return 0;
		default: // If the user enters an incorrect number, they can retry.
			std::cout << "Please enter a valid option." << std::endl;
			proceed = false;
			Util::PauseClear();
			break;
		}

	} while (proceed == false);

	return 0;


}