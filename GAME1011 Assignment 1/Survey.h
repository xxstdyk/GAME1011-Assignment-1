#pragma once
#ifndef __SURVEY__
#define __SURVEY__

#include <sstream>
#include <iostream>
#include <map>
#include <iomanip>
#include "Person.h"

class Survey {

	// member variables
	private:
	Person **m_studentArray;

	int m_numStudents;

	// Enum to track student type for arrays
	enum StudentType { GAMER, NON_GAMER };

	// the arrays
	std::map<std::string, int> m_preferredEntertainmentValues[2]; // tracks how many times each service comes up
	std::string m_preferredEntertainment[2]; // tracks the top service
	int m_avgAges[2];
	float m_avgHours[2];
	int m_studentCount[2];

	public:

	// Constructor
	Survey(Person **_studentArray, int _numStudents) {

		this->m_studentArray = _studentArray;
		this->m_numStudents = _numStudents;
	}

	void Process() {

		// O(nLog(n))
		for (int i = 0; i < m_numStudents; ++i) {

			auto tmp = m_studentArray[i]->GetInfo();
			StudentType type = tmp.m_isGamer ? GAMER : NON_GAMER;

			// Set the easy values
			m_studentCount[type]++;
			m_avgAges[type] += tmp.m_age;
			m_avgHours[type] += tmp.m_hoursWasted;

			// O(Log(n))
			// Incriment the counter for each entertainment type, or create it if it doesn't exist
			if (!m_preferredEntertainmentValues[type].count(tmp.m_entertainment))
				m_preferredEntertainmentValues[type].insert({ tmp.m_entertainment, 0 });
			else
				m_preferredEntertainmentValues[type][tmp.m_entertainment]++;
		}

		// O(2n)
		for (int x = 0; x < 2; ++x) {

			// Actually average the values here after all the collection is done
			m_avgAges[x] /= m_studentCount[x];
			m_avgHours[x] /= m_studentCount[x];

			std::string entertainment;
			int record = -1;

			// O(n)
			// Loop to find the actual top entertainments
			for (const auto &kv : m_preferredEntertainmentValues[x]) {
				// if the value (kv.second) is greater than the running record, set the entertainment to the key (kv.first)
				if (kv.second > record) {
					entertainment = kv.first;
					record = kv.second;
				}
			}

			m_preferredEntertainment[x] = entertainment;
		}
	}

	std::string Display() const {	//Displays the data to the user
		std::stringstream ss;

		ss << "Stats for GAMERS" << std::endl;
		ss << "----------------" << std::endl;
		ss << std::left << std::setw(25) << "Avgerage Age: " <<  m_avgAges[GAMER] << std::endl;
		ss << std::left << std::setw(25) << "Average Hours Wasted: " << std::setprecision(2) << m_avgHours[GAMER] << std::endl;
		ss << std::left << std::setw(25) << "Top Platform: " <<  m_preferredEntertainment[GAMER] << std::endl;
		ss << std::left << std::setw(25) << "Student Count: " <<  m_studentCount[GAMER] << std::endl;


		ss << "\n\nStats for NON-GAMERS" << std::endl;
		ss << "----------------" << std::endl;
		ss << std::left << std::setw(25) << "Average Age: "  << m_avgAges[NON_GAMER] << std::endl;
		ss << std::left << std::setw(25) << "Average Hours Wasted: " << std::setprecision(2) << m_avgHours[NON_GAMER] << std::endl;
		ss << std::left << std::setw(25) << "Top Platform: "  << m_preferredEntertainment[NON_GAMER] << std::endl;
		ss << std::left << std::setw(25) << "Student Count: " << m_studentCount[NON_GAMER] << std::endl;

		return ss.str();
	}

	// Accessors & Mutators
	const int GetNumStudents(int _type) { return this->m_studentCount[_type]; }
	const std::string GetTopPlatform(int _type) { return this->m_preferredEntertainment[_type]; }
	const float GetAverageAge(int _type) { return this->m_avgAges[_type]; }
	const float GetAverageHours(int _type) { return this->m_avgHours[_type]; }
};

// ostream << operator to interface with survey class to make output very nice
std::ostream &operator<<(std::ostream &os, Survey &s) {
	os << s.Display();
	return os;
}

#endif