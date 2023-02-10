//Filename: Toy.h
//Name:	Shawn Ogbomo
// Student #022609127
// date: 02/09/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#ifndef SDDS_TOY_H_
#define SDDS_TOY_H_
#include <string>
#include <iostream>
namespace sdds {
	class Toy {
		//if cpy-ctor is called used inclass initialization
		static constexpr double harmonized_sales_tax = 0.13;
		static constexpr int max_id_size = 7;
	public:
		Toy();
		Toy(const std::string& toy);
		void update(int numItems);
	private:
		unsigned order_id;
		std::string name;
		unsigned amount;
		double price;
		double hst;
		friend std::ostream& operator <<(std::ostream& os, const Toy& t);
	};
}
#endif//!SDDS_TOY_H