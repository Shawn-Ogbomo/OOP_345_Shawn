//Filename: Child.cpp
//Name:	Shawn Ogbomo
// Student #022609127
// date: 02/09/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include "Child.h"
namespace sdds {
	Child::Child(std::string name, int age, const Toy* toys[], size_t count)
		: name{ name },
		age{ age },
		toys{ toys },
		count{ count } {
	}
	size_t Child::size() const {
		return count;
	}
	std::ostream& operator<<(std::ostream& os, const Child& c) {
		static int CALL_CNT{};
		++CALL_CNT;
		if (!c.size()) {
			return os << "--------------------------\n" << "Child" << CALL_CNT << ":" << "  " << c.age << " years old:"
				<< "--------------------------\n" << "  This child has no toys! " << "--------------------------\n";
		}
		os << "--------------------------\n" << "Child" << CALL_CNT << ": " << c.name << "  " << c.age << " years old:"
			<< "\n--------------------------\n";
		for (auto i = 0; i < c.count; ++i) {
			os << *c.toys[i];
		}
		os << "--------------------------\n";
		return os;
	}
}