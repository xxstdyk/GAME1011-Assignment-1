#include <fstream>
#include <vector>
#include <ctime>

#include "Survey.h"
#include "Pools.h"

// you gotta at least let me use it for this it's not even one of the requirements !
std::vector<std::string> first_names;
std::vector<std::string> last_names;

int main() {

	{ 
		std::ifstream istream;

		// Reading in a list of first names
		istream.open("names.txt");

		if (istream.is_open()) {
			std::string name;
			while (getline(istream, name))
				first_names.push_back(name);

		} else
			std::cerr << "Names file not found." << std::endl;

		istream.close();

		// Reading in a list of last names
		istream.open("last-names.txt");

		if (istream.is_open()) {
			std::string lastName;
			while (getline(istream, lastName))
				last_names.push_back(lastName);

		} else
			std::cerr << "Last Names file not found." << std::endl;

		istream.close();
	}

	srand(std::time(NULL));

	int numParticipants; // put the number of participants in here

	std::cout << "Welcome." << std::endl;
	std::cout << "How many participants are going to participate in the survey?" << std::endl;
	std::cout << "Note: This program allows a maximum of 500 participants." << std::endl;
	Util::GetIntInRange(&numParticipants, 1, 500);

	Util::ClearScreen();

	Person **tmp_arr = new Person*[numParticipants];
	
	for (int i = 0; i < numParticipants; ++i) {


		if (rand() % 2) { 
		
			GamingStudent *tmp_student = new GamingStudent;

			tmp_student->SetCollege(Pool::COLLEGES[rand() % Pool::NUM_COLLEGES]);

			tmp_arr[i] = tmp_student;
		} 
		
		else { 
		
			NonGamingStudent *tmp_student = new NonGamingStudent;

			tmp_arr[i] = tmp_student;
		}
	}

	Survey s(tmp_arr, numParticipants);

	int userIn;
	std::cout << "Are you ready to process the servey?" << std::endl;
	std::cout << "[1] Yes\t[2] Exit" << std::endl;
	Util::GetIntInRange(&userIn, 1, 500);


	switch (userIn) { 
		case 1:
			s.Process();
			break;

		case 2:
			return 1;
	}

	// TODO:
	//s.Display();

	return 0;


}