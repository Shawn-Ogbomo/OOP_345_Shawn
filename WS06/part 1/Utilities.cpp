//Filename: Utilities.cpp
//Name:	Shawn Ogbomo
// Student #022609127
// date: 03/03/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include <sstream>
#include <iostream>
#include <string>
#include "Utilities.h"
namespace sdds {
	Person* buildInstance(std::istream& in) {
		const char employee = 'e';

		if (in.peek() != employee) {
			return nullptr;
		}
		std::string s;
		std::stringstream s1;
		getline(in, s);
		s1 << s;
		Person* p = new Employee{ s1 };
		return p;
	}
}