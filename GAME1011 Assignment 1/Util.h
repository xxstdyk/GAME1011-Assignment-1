#pragma once
#ifndef __UTIL__
#define __UTIL__

#include <iostream>
#include <string>

class Util {

	public:

	/// <summary>
	/// Input validation on std::cin for int values
	/// </summary>
	/// <param name="_val"> The value to store the input in</param>
	static void GetInt(int *_val) {

		std::cin >> *_val;
		std::cout << std::endl;

		if (std::cin.fail()) {

			std::cout
				<< "There was an error with your last input.\n"
				<< "Please try again: ";

			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');

			GetInt(_val);
		}
	}

	/// <summary>
	/// Input validation on std::cin for ints that need to be bound to a range
	/// </summary>
	/// <param name="_val"> The value to store the input to</param>
	/// <param name="_min"> The lower bound. Inclusive</param>
	/// <param name="_max"> The upper bound. Inclusive</param>
	static void GetIntInRange(int *_val, int _min, int _max) {

		GetInt(_val);

		while (*_val < _min || *_val > _max) {

			std::cout
				<< "Error: Input must be between "
				<< _min << " and " << _max << ".\n"
				<< "Please try again: ";

			GetInt(_val);
		}
	}

	/// <summary>
	/// Clears the consol and flushes
	/// </summary>
	static void ClearScreen() {
		system("CLS");
		std::cout << std::flush;
	}

	/// <summary>
	/// Waits for user's permission to continue and clear the screen
	/// </summary>
	static void PauseClear() {
		system("PAUSE");
		ClearScreen();
	}

};

#endif