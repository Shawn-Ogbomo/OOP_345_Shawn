//Filename: Child.cpp
//Name:	Shawn Ogbomo
// Student #022609127
// date: 02/09/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include "Child.h"
namespace sdds {
	Child::Child(const std::string& name, int age, const Toy* toys[], size_t count)
		: name{ name },
		age{ age },
		count{ count },
		toys{ new const Toy * [count] } {
		for (unsigned i = 0; i < count; ++i) {
			this->toys[i] = new const Toy{ *toys[i] };
		}
	}
	Child::Child(const Child& c) {
		*this = c;
	}

	Child::Child(Child&& c) {
		*this = std::move(c);
	}

	Child::~Child() {
		for (unsigned i{}; i < count; ++i) {
			delete toys[i];
		}
		delete[] toys;
	}

	Child& Child::operator=(Child&& right) {
		if (this != &right) {
			for (unsigned i = 0; i < count; ++i) {
				delete toys[i];
			}
			delete[] toys;
			name = right.name;
			age = right.age;
			count = right.count;
			toys = right.toys;
			right.toys = nullptr;
			right.name = "";
			right.age = 0;
			right.count = 0;
		}
		return *this;
	}

	size_t Child::size() const {
		return count;
	}
	Child& Child::operator=(const Child& right) {
		if (this != &right) {
			for (unsigned i = 0; i < count; ++i) {
				delete toys[i];
			}
			delete[] toys;
			name = right.name;
			age = right.age;
			count = right.count;
			toys = new const Toy * [count];
			for (unsigned i = 0; i < count; ++i) {
				toys[i] = new const Toy{ *right.toys[i] };
			}
		}
		return *this;
	}
	std::ostream& operator<<(std::ostream& os, const Child& c) {
		static int CALL_CNT{};
		++CALL_CNT;
		if (!c.size()) {
			return os << "--------------------------\n" << "Child " << CALL_CNT << ":" << "  " << c.age << " years old:\n"
				<< "--------------------------\n" << "This child has no toys!\n" << "--------------------------\n";
		}
		os << "--------------------------\n" << "Child " << CALL_CNT << ": " << c.name << " " << c.age << " years old:"
			<< "\n--------------------------\n";
		for (auto i = 0u; i < c.count; ++i) {
			os << *c.toys[i];
		}
		os << "--------------------------\n";
		return os;
	}
}