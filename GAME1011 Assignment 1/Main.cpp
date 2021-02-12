/*
* GAME1011 - Wally Balaniuc
* Assignment 1
* 02/10/2021
*
* Nicholas Oostdyk, 101335730
* Cassandra Didier, 101128745
*/

#include <fstream>
#include <vector>
#include <ctime>

#include "Survey.h"
#include "Pools.h"

int GetRandomAge(int);

// you gotta at least let me use it for this it's not even one of the requirements !
std::vector<std::string> first_names, last_names, names;

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

	srand(std::time(NULL));

	int numParticipants;

	std::cout << "Welcome." << std::endl;
	std::cout << "How many participants are going to participate in the survey?" << std::endl;
	std::cout << "Note: This program allows a maximum of 500 participants." << std::endl;
	Util::GetIntInRange(&numParticipants, 1, 500);

	Util::ClearScreen();

	// Generate names of all the people
	for (int i = 0; i < numParticipants; ++i)
		names.push_back(first_names[rand() % first_names.size()] + " " + last_names[rand() % last_names.size()]);

	// Create a temporary array to hold all the people
	Person **tmpArr = new Person * [numParticipants];

	// Randomly generate numParticipants random students
	for (int i = 0; i < numParticipants; ++i) {

		if (rand() % 5 < 3) { // chance of student being a gamer is 3/5ths 

			GamingStudent *tmpStudent = new GamingStudent;

			// set values here
			tmpStudent->SetName(names[i]);
			tmpStudent->SetAge(GetRandomAge(17));

			tmpStudent->SetCollege(Pool::COLLEGES[rand() % Pool::NUM_COLLEGES]);
			tmpStudent->SetProgram(Pool::PROGRAMS[rand() % Pool::NUM_PROGRAMS]);
			tmpStudent->SetSemester(rand() % 8 + 1);

			tmpStudent->SetDevice(Pool::GAMING_DEVICES[rand() % Pool::NUM_GAMING_DEVICES]);
			tmpStudent->SetHours(rand() % 50 + 1);

			tmpArr[i] = tmpStudent;
		}

		else {

			NonGamingStudent *tmpStudent = new NonGamingStudent;

			tmpStudent->SetName(names[i]);
			tmpStudent->SetAge(GetRandomAge(17));

			tmpStudent->SetCollege(Pool::COLLEGES[rand() % Pool::NUM_COLLEGES]);
			tmpStudent->SetProgram(Pool::PROGRAMS[rand() % Pool::NUM_PROGRAMS]);
			tmpStudent->SetSemester(rand() % 8 + 1);

			tmpStudent->SetService(Pool::STREAMING_SERVICES[rand() % Pool::NUM_STREAMING_SERVICES]);
			tmpStudent->SetHours(rand() % 50 + 1);

			tmpArr[i] = tmpStudent;
		}

	}

	Survey survey(tmpArr, numParticipants);

	int userIn;
	std::cout << "Are you ready to process the servey?" << std::endl;
	std::cout << "[1] Yes\t[2] Exit" << std::endl;
	Util::GetIntInRange(&userIn, 1, 500);

	switch (userIn) {
		case 1:
			survey.Process();
			std::cout << survey << std::endl;
			break;

		case 2:
			break;
	}

	return 0;
}

// Gets a random age, with a bias towards younger students
int GetRandomAge(int age) {

	if (rand() % 100 < 85 && age < 80) {
		age += rand() % 4;
		return GetRandomAge(age);
	} else {
		return age;
	}
}