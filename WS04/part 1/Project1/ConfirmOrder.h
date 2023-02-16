//Filename: ConfirmOrder.h
//Name:	Shawn Ogbomo
// Student #022609127
// date: 02/09/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include "Toy.h"
#ifndef SDDS_CONFIRMORDER_H_
#define SDDS_CONFIRMORDER_H_
namespace sdds {
	class ConfirmOrder {
	public:
		ConfirmOrder();
		ConfirmOrder& operator+=(const Toy& toy);
		ConfirmOrder& operator-=(const Toy& toy);
		friend std::ostream& operator << (std::ostream& os, const ConfirmOrder& c);
	private:
		const Toy** toys{};
		unsigned count{};
	};
}
#endif//!SDDS_CONFIRMORDER_H