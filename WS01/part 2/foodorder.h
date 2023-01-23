//Filename: foodorder.h
///Name:	Shawn Ogbomo
// Student #022609127
// date: 01/23/23
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#ifndef SDDS_FOODORDER_H
#define SDDS_FOODORDER_H
#include <iostream>
extern double g_taxrate;
extern double g_dailydiscount;
namespace sdds {
	class FoodOrder {
	public:
		FoodOrder();
		void read(std::istream& is);
		void display() const;
		FoodOrder(const FoodOrder& f);
		FoodOrder& operator=(const FoodOrder& rhs);
		~FoodOrder();
	private:
		char customer_name[10];
		char* description;
		double price;
		bool special;
	};
}
#endif // !SDDS_FOODORDER_H