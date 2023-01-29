//Filename: ProteinDatabase.cpp
//Name:	Shawn Ogbomo
// Student #022609127
// date: 01/29/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <string>
#include <iostream>
#include "ProteinDatabase.h"
sdds::ProteinDatabase::ProteinDatabase()
	:elements{},
	element_count{} {
}

sdds::ProteinDatabase::ProteinDatabase(const char* file_name)
	: elements{},
	element_count{}{
	std::ifstream ifs{ file_name };
	if (!ifs) {
		ifs.exceptions(ifs.exceptions() | std::ios_base::badbit);
	}
	char* s;
	std::string str;
	char c{};
	while (ifs) {
		if (ifs.peek() == '>') {
			ifs.ignore();
		}
		if (std::getline(ifs, str, '>')) {
			s = new char[str.length() + 1];
			std::strcpy(s, str.c_str());
			++element_count;
			str = "";
			delete[] s;
		}
	}
}

size_t sdds::ProteinDatabase::size() {
	return element_count;
}

std::string sdds::ProteinDatabase::operator[](size_t index) {
	if (elements) {
		return elements[index];
	}
	return std::string{};
}