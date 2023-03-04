//Filename: College.cpp
//Name:	Shawn Ogbomo
// Student #022609127
// date: 03/03/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include "College.h"
namespace sdds {
	College::College() = default;

	College& College::operator+=(Person* thePerson) {
		m_persons.push_back(thePerson);
		return *this;
	}
	void College::display(std::ostream& out) const {
		out << "------------------------------------------------------------------------------------------------------------------------\n"
			<< "|                                        Test #1 Persons in the college!                                               |\n"
			<< "------------------------------------------------------------------------------------------------------------------------\n";
		for (auto it = m_persons.begin(); it != m_persons.end(); ++it) {
			(*it)->display(out);
			out << "\n";
		}
		out << "------------------------------------------------------------------------------------------------------------------------\n"
			<< "|                                        Test #2 Persons in the college!                                               |\n"
			<< "------------------------------------------------------------------------------------------------------------------------\n";
		for (const auto& person : m_persons) {
			(*person).display(out);
			out << "\n";
		}
	}
	College::~College() {
		for (const auto& v : m_persons) {
			delete v;
		}
	}
}