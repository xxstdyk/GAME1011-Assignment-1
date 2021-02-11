#include <fstream>
#include <vector>

#include "Pools.h"
#include "Survey.h"


// you gotta at least let me use it for this it's not even one of the requirements !
std::vector<std::string> first_names;
std::vector<std::string> last_names;

int main() {

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

	// Cass do the menu here please thanks lov u : )

	int numParticipants; // put the number of participants in here
	
	for (int i = 0; i < numParticipants; ++i) {

	}

	return 0;
}