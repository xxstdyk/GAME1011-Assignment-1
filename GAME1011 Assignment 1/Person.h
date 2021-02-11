#pragma once
#ifndef __PERSON__
#define __PERSON__

#include "Util.h"

// handy utility struct to help pass the data through to the survey
struct SurveyData {

	bool m_isGamer;
	int m_age;
	std::string m_entertainment;
	int m_hoursWasted;
};

// Base class 
class Person {

	protected:
	std::string m_name;
	int m_age;

	public:
	// Pure virtual function to make the class abstract
	virtual SurveyData GetInfo() = 0;
	
	// Accessors & Mutators
	std::string GetName() const { return this->m_name; }
	void SetName(const std::string _name) { this->m_name = _name; }

	int GetAge() const { return this->m_age; }
	void SetAge(int _age) { this->m_age = _age; }

};

// child 1 of base class, Student is a Person
// Student is also an abstract class because it doesnt override Person::GetInfo()
class Student : public Person {

	// Some bonus information that is never used :O
	protected:
	std::string m_college;
	std::string m_program;
	int m_semNum;

	public:
	// Accessors & Mutators
	std::string GetCollege() const { return this->m_college; }
	void SetCollege(const std::string _college) { this->m_college = _college; }

	std::string GetProgram() const { return this->m_program; }
	void SetProgram(const std::string _program) { this->m_program = _program; }

	int GetSemester() const { return this->m_semNum; }
	void SetSemester(const int _semNum) { this->m_semNum = _semNum; }
};

// child a of child 1, NonGamingStudent is a Student
class NonGamingStudent : public Student {

	protected:
	std::string m_streamingService;
	int m_hoursNotGaming;

	public:
	// GetInfo virtual function override
	SurveyData GetInfo() override { 
	
		SurveyData tmpData;

		tmpData.m_isGamer = false;
		tmpData.m_age = m_age;
		tmpData.m_entertainment = m_streamingService;
		tmpData.m_hoursWasted = m_hoursNotGaming;

		return tmpData;
	}

	// Accessors & Mutators

};

// child b of child 1, GamingStudent is a Student
class GamingStudent : public Student {

	protected:
	std::string m_device;
	int m_hoursGaming;

	public:
	// GetInfo virtual function override
	SurveyData GetInfo() override {
		
		SurveyData tmpData;

		tmpData.m_isGamer = true;
		tmpData.m_age = m_age;
		tmpData.m_entertainment = m_device;
		tmpData.m_hoursWasted = m_hoursGaming;

		return tmpData;
	}

	// Accessors & Mutators
};

#endif
