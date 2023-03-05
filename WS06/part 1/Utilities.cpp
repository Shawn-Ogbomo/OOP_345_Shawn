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
		const char student = 's';
		const char professor = 'p';
		char tag = in.peek();
		if (tag != employee && tag != student && tag != professor) {
			return nullptr;
		}
		std::string s;
		std::stringstream s1;
		getline(in, s);
		s1 << s;
		/*	if (tag == student) {
				Person* p = new Student{ s1 };
				return p;
			}*/
		if (tag == professor) {
			Person* p = new Professor{ s1 };
			return p;
		}
		Person* p = new Employee{ s1 };
		return p;
	}
}