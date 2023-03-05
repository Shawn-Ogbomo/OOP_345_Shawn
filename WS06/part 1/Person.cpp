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

		if (is.fail()) {
			throw std::string{ m_name + "++Invalid record!" };
		}
		if (is.peek() == ',') {
			is.get();
		}

		if (isspace(is.peek())) {
			is.get();
		}

		std::getline(is, m_id, ',');
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
	void Employee::display(std::ostream& out) const {
		out << std::left << "| " << std::setw(10) << Employee::status() << "| " << std::setw(10)
			<< id() << "| " << std::setw(20) << name() << " | " << std::setw(3) << age() << " |";
	}
	Employee::~Employee() = default;

	Professor::Professor(std::istream& in)
		:Employee(in) {
		if (isspace(in.peek())) {
			in.get();
		}
		std::getline(in, m_department);
	}

	void Professor::display(std::ostream& out) const {
		Employee::display(out);
		out << department() << "| " << status();
	}

	std::string Professor::status() const {
		return "Professor";
	}
	std::string Professor::department() const
	{
		return m_department;
	}
	Professor::~Professor() = default;

	Student::Student(std::istream& in) {
		const char student_id = 'S';
		const char space = ' ';
		std::string s;
		std::getline(in, s, space);
		std::getline(in, m_name, ',');
		auto pos = m_name.find(space);
		if (pos != std::string::npos) {
			auto pos2 = m_name.find(space, pos + 1);
			if (pos2 != std::string::npos) {
				m_name.erase(m_name.begin() + pos2, m_name.end());
			}
		}

		in >> m_age;

		if (in.fail()) {
			throw std::string{ m_name + "++Invalid record!" };
		}

		in.get();

		if (isspace(in.peek())) {
			in.get();
		}

		std::getline(in, m_id, ',');

		if (m_id.front() != student_id) {
			throw std::string{ m_name + "++Invalid record!" };
		}

		in >> m_count;
		in.get();
		if (isspace(in.peek())) {
			in.get();
		}
		for (unsigned i = 0; i < m_count; ++i) {
			std::string course;
			std::getline(in, course, ',');
			if (in.peek() == ',') {
				in.get();
			}
			if (isspace(in.peek())) {
				in.get();
			}
			m_courses.push_back(new std::string{ course });
		}
	}
	Student::~Student() {
		for (const auto& course : m_courses) {
			delete course;
		}
	}

	std::string Student::status() const {
		return "Student";
	}
	std::string Student::name() const {
		return m_name;
	}
	std::string Student::age() const {
		return std::to_string(m_age);
	}
	std::string Student::id() const {
		return m_id;
	}
	void Student::display(std::ostream& out) const {
		out << std::left << "| " << std::setw(10) << status() << "| " << std::setw(10) << id() << "| " << std::setw(20) << name() << " | " << std::setw(3) << age() << " |";
		for (auto& course : m_courses) {
			if (course != m_courses.back()) {
				out << *course << ", ";
				continue;
			}
			out << *course;
		}
	}
}