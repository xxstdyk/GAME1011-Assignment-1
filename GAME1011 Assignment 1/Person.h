#pragma once
#ifndef __PERSON__
#define __PERSON__

#include "Util.h"

class Person {

	protected:
	std::string m_name;
	int m_age;

	public:

};

class Student : public Person {

	protected:
	std::string m_college;
	std::string m_program;
	int m_semNum;
};

class NonGamingStudent : public Student {

	protected:
	std::string m_streamingService;
	int m_hoursNotGaming;
};

class GamingStudent : public Student {

	protected:
	std::string m_device;
	int m_hoursGaming;
};

#endif
