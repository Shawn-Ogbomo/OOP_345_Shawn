//Filename: pair.cpp
//Name:	Shawn Ogbomo
// Student #022609127
// date: 02/04/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include <string>
#include <iostream>
#include <iomanip>
#include "Pair.h"
namespace sdds {
	std::ostream& operator<<(std::ostream& os, Pair& p) {
		return os << std::setw(20) << p.getKey() << ":" << " " << p.getValue();
	}
	Pair::Pair() : m_key{}, m_value{}{
	}
}