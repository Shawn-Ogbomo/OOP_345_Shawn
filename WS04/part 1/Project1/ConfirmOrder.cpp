//Filename: ConfirmOrder.cpp
//Name:	Shawn Ogbomo
// Student #022609127
// date: 02/09/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include "ConfirmOrder.h"
namespace sdds {
	ConfirmOrder::ConfirmOrder()
		:toys{},
		count{}	{
	}
	ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy) {
		for (unsigned i = 0; i < count; ++i) {
			if (toys[i] == &toy) {
				return *this;;
			}
		}
		++count;
		toys = new const Toy * [count];
		for (unsigned i = 0; i < count; ++i) {
			toys[i] = &toy;
		}
		return *this;
	}
	std::ostream& operator<<(std::ostream& os, const ConfirmOrder& c) {
		if (!c.count) {
			return os << "--------------------------\n" << "Confirmations to Send\n"
				<< "--------------------------\n" << "There are no confirmations to send!\n"
				<< "--------------------------";
		}
		/*os << "--------------------------\n" << "Child " << CALL_CNT << ": " << c.name << " " << c.age << " years old:"
			<< "\n--------------------------\n";
		for (auto i = 0u; i < c.count; ++i) {
			os << *c.toys[i];
		}
		os << "--------------------------\n";
		return os;*/
	}
}