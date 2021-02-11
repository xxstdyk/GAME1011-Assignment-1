#pragma once
#ifndef __PERSON__
#define __PERSON__

#include "Util.h"

struct SurveyData {

	bool m_isGamer;
	int m_age;
	std::string m_entertainment;
	int m_hoursWasted;
};

class Person {

	protected:
	std::string m_name;
	int m_age;

	public:
	virtual SurveyData GetInfo() = 0;

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

	public:
	SurveyData GetInfo() override { 
	
	}
};

class GamingStudent : public Student {

	protected:
	std::string m_device;
	int m_hoursGaming;

	public:
	SurveyData GetInfo() override {

	}
};

#endif
