//Filename: Person.cpp
//Name:	Shawn Ogbomo
// Student #022609127
// date: 03/03/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include <iomanip>
#include <cctype>
#include "Person.h"
namespace sdds {
	Employee::Employee(std::istream& is) {
		const char employee_id = 'E';
		const char space = ' ';
		std::string s;
		std::getline(is, s, space);
		std::getline(is, m_name, ',');
		auto pos = m_name.find(space);
		if (pos != std::string::npos) {
			auto pos2 = m_name.find(space, pos + 1);
			if (pos2 != std::string::npos) {
				m_name.erase(m_name.begin() + pos2, m_name.end());
			}
		}

		is >> m_age;

		if (!is) {
			throw std::string{ m_name + "++Invalid record!" };
		}
		if (is.peek() == ',') {
			is.get();
		}

		if (isspace(is.peek())) {
			is.get();
		}

		std::getline(is, m_id, space);
		if (m_id.front() != employee_id) {
			throw std::string{ m_name + "++Invalid record!" };
		}
	}
	std::string Employee::status() const {
		return "Employee";
	}
	std::string Employee::name() const {
		return m_name;
	}
	std::string Employee::age() const {
		return std::to_string(m_age);
	}
	std::string Employee::id() const {
		return m_id;
	}
	void Employee::display(std::ostream&) const {
		std::cout << std::left << "|" << std::setw(10) << status() << " |"
			<< id() << "|" << std::setw(20) << name() << "|" << std::setw(3) << age();
	}
}