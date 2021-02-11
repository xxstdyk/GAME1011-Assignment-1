#pragma once
#ifndef __SURVEY__
#define __SURVEY__

#include <map>

#include "Person.h"

class Survey {

	private:
	Person **m_studentArray;

	int m_numStudents;

	enum { GAMER, NON_GAMER };
	std::map<std::string, int> m_preferredEntertainment[2];
	float m_avgAges[2];
	float m_avgHours[2];
	int m_studentCount[2];

	public:

	// Constructor
	Survey(Person **_studentArray, int _numStudents) { 

		this->m_studentArray = _studentArray;
		this->m_numStudents = _numStudents;
	}

	void Process() { 
	
		for (int i = 0; i < m_numStudents; ++i) {
			
			auto tmp = m_studentArray[i]->GetInfo();
		}
	}
};

#endif