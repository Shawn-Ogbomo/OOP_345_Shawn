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
				return *this;
			}
		}
		++count;
		if (count > 1) {
			const Toy** temp = new const Toy * [count - 1];
			for (unsigned i = 0; i < count - 1; ++i) {
				temp[i] = toys[i];
			}
			delete[] toys;
			toys = new const Toy * [count];
			for (unsigned i = 0; i < count - 1; ++i) {
				toys[i] = temp[i];
			}
			toys[count - 1] = &toy;
			delete[] temp;
			return *this;
		}
		toys = new const Toy * [count];
		toys[count - 1] = &toy;
		return *this;
	}
	ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy) {			//fix this
		/*for (unsigned i = 0; i < count; ++i) {
			if (toys[i] == &toy) {
				toys[i] = nullptr;
				const Toy** temp = new const Toy * [count - 1];
				for (unsigned j = 0; j < count - 1; ++j) {
					if (toys[j]) {
						temp[j] = toys[j];
					}
					else if (!temp[j] && toys[j + 1]) {
						temp[j] = toys[j + 1];
						++j;
					}
				}
				--count;
				delete[] toys;
				toys = new const Toy * [count];
				for (unsigned k = 0; k < count - 1; ++k) {
					toys[k] = temp[k];
				}
				delete[] temp;
				return *this;
			}
		}
		return *this;*/
		for (unsigned i = 0; i < count; ++i)
			if (toys[i] == &toy) {
				toys[i] = nullptr;
				const Toy** temp = new const Toy * [count - 1];
				for (unsigned j = 0, k = 0; j < count; ++j) {
					if (toys[j]) {
						temp[k] = toys[j];
						++k;
					}
				}
				delete[] toys;
				--count;
				toys = new const Toy * [count];
				for (unsigned i = 0; i < count; ++i) {
					toys[i] = temp[i];
				}
				delete[] temp;
				return *this;
			}
		return *this;
	}
	std::ostream& operator<<(std::ostream& os, const ConfirmOrder& c) {
		if (!c.count) {
			return os << "--------------------------\n" << "Confirmations to Send\n"
				<< "--------------------------\n" << "There are no confirmations to send!\n"
				<< "--------------------------\n";
		}
		os << "--------------------------\n" << "Confirmations to Send\n"
			<< "--------------------------\n";
		for (auto i = 0u; i < c.count; ++i) {
			os << *c.toys[i];
		}
		os << "--------------------------";
		return os;
	}
}