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
	while (ifs) {
		if (ifs.peek() == '>') {
			ifs.ignore();
		}
		if (std::getline(ifs, str, '>')) {
			s = new char[str.length() + 1];
			std::strcpy(s, str.c_str());
			++element_count;
			str.clear();
			delete[] s;
		}
	}
	elements = new std::string[element_count];
	ifs.clear();
	ifs.seekg(0, std::ios::beg);
	std::string protien_sequence;
	for (int i = 0; (i < element_count); ++i) {
		ifs.ignore(1000, '\n');
		while (ifs.peek() != '>' && (!ifs.eof())) {
			ifs >> str;
			protien_sequence += str;
			ifs.ignore();
		}
		elements[i] = protien_sequence;
		protien_sequence.clear();
	}
}
sdds::ProteinDatabase::ProteinDatabase(const ProteinDatabase& p) {
	*this = p;
}
//while (ifs) {
//	if (ifs.peek() == '>') {
//		ifs.ignore();
//	}
//	if (std::getline(ifs, str, '>')) {
//		int pos = str.find("SV=1", 0);
//		str.erase(str.find("tr|", 0), pos + 5);
//		//elements[0] = new char[str.length() + 1];
//		elements[0] = str;
//		str = "";

//	}
//}

sdds::ProteinDatabase::~ProteinDatabase() {
	delete[] elements;
	elements = nullptr;
}

size_t sdds::ProteinDatabase::size() {
	return element_count;
}

std::string sdds::ProteinDatabase::operator[](size_t index) {
	if (index >= 0 && index < element_count) {
		return elements[index];
	}
	return std::string{};
}

sdds::ProteinDatabase& sdds::ProteinDatabase::operator=(const ProteinDatabase& right) {
	if (this != &right) {
		elements = right.elements;
		element_count = right.element_count;
	}
	return *this;
}