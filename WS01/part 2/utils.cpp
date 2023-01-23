//Final Project Milestone 1
//Filename: Utils.cpp
//Version 1.0
//Name:	Shawn Ogbomo
// Student #022609127
// date: 03/16/22
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "utils.h"
using namespace std;
namespace sdds {
	void sdds::Utils::alocpy(char*& destination, const char* source) {
		delete[] destination;
		destination = nullptr;
		if (source != nullptr)
		{
			destination = new char[std::strlen(source) + 1];
			std::strcpy(destination, source);
		}
	}
}