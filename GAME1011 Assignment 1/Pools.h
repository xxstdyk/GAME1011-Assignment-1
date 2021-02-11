#pragma once
#ifndef __POOLS__
#define __POOLS__

#include <string>

namespace Pool {

	// Hardcoded list of colleges
	static const int NUM_COLLEGES = 7;
	static std::string COLLEGES[NUM_COLLEGES] = {
		"George Brown College",
		"Seneca College",
		"Centennial College",
		"York University",
		"Humber College",
		"University of Toronto",
		"Ryserson University",
	};

	// Hardcoded list of programs
	static const int NUM_PROGRAMS = 50;
	static std::string PROGRAMS[NUM_PROGRAMS] = {
		"Business",
		"Game Programming",
		"Linguistics",
		"Computer Science",
		"User Experience Design",
		"Architecture",
		"Applied Mathematics",
		"Hygenics",
		"English",
		"French",
		"Spanish",
		"Mandarin",
		"Japanese",
		"East Asian Studies",
		"Italian",
		"South American Studies"
		"Nursing",
		"Forensics",
		"Bio-Chemistry",
		"Kinesiology",
		"Film",
		"Dance",
		"History",
		"Sociology",
		"Psychology",
		"Chemistry",
		"Zoology",
		"Game Design",
		"Accounting",
		"Graphic Design",
		"Anthropology",
		"Financial Economics",
		"Drama",
		"Environmental Science",
		"Criminology",
		"Data Science",
		"Animation and 3D Modeling",
		"ASL Translation",
		"Jewelery Making",
		"Interaction Design",
		"Software Engineering",
		"Fashion Technology",
		"Sound Design and Production",
		"Professional Writing",
		"Construction and Engineering",
		"Plumbing",
		"Dental Hygiene",
		"Fitness and Health",
		"Neutrition",
		"Office Administration",
		"Education",
	};

	// Hardcoded list of streaming services
	static const int NUM_STREAMING_SERVICES = 14;
	static std::string STREAMING_SERVICES[NUM_STREAMING_SERVICES] = {
		"Netflix",
		"Crunchyroll",
		"Prime Video",
		"Crave",
		"HBO Max",
		"Disney Plus",
		"Hulu",
		"Crackle",
		"Apple TV",
		"Criterion Channel",
		"CBC Gem",
		"CTV",
		"Paramount Plus",
		"Pornhub"
	};

	// Hardcoded list of gaming devices
	static const int NUM_GAMING_DEVICES = 10;
	static std::string GAMING_DEVICES[NUM_GAMING_DEVICES] = {
		"Nintendo Switch",
		"PC",
		"Xbox",
		"Play Station",
		"Wii",
		"Gameboy",
		"Mobile",
		"Nintendo 3DS",
		"Atari",
		"Tamogachi"
	};
}

#endif