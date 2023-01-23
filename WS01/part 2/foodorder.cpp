//Filename: foodorder.cpp
///Name:	Shawn Ogbomo
// Student #022609127
// date: 01/23/23
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iomanip>
#include<cstring>
#include "foodorder.h"
#include "utils.h"
namespace sdds {
	sdds::FoodOrder::FoodOrder()
		:customer_name{},
		description{},
		price{},
		special{ false }{
	}

	void sdds::FoodOrder::read(std::istream& is) {
		static constexpr char no = 'N';
		if (is) {
			std::string name;
			std::getline(is, name, ',');
			std::strcpy(customer_name, name.c_str());
			std::string details;
			std::getline(is, details, ',');
			sdds::Utils::alocpy(description, details.c_str());
			is >> price;
			is.ignore();
			if (is.peek() == no) {
				special = false;
			}
			else {
				special = true;
			}
			is.ignore();
			is.ignore();
		}
	}
	void FoodOrder::display() const {
		static int counter{};
		++counter;
		const int name_len = std::strlen(customer_name);
		if (name_len) {
			std::cout << std::left << std::setw(2) << counter << ". " << std::setw(10) << customer_name <<
				"|" << std::setw(25) << description << "|" << std::setw(12) <<
				std::setprecision(2) << std::fixed << price + (price * g_taxrate) << "|";
			if (special) {
				std::cout << std::right << std::setw(13) << (price + (price * g_taxrate)) - (g_dailydiscount);
			}
		}
		else {
			std::cout << counter << std::left << std::setw(2) << ". ""No Order";
		}

		std::cout << "\n";
	}
	FoodOrder::FoodOrder(const FoodOrder& f) {
		*this = f;
	}
	FoodOrder& FoodOrder::operator=(const FoodOrder& rhs) {
		if (this != &rhs) {
			std::strcpy(customer_name, rhs.customer_name);
			description = new char[std::strlen(rhs.description) + 1];
			std::strcpy(description, rhs.description);
			price = rhs.price;
			special = rhs.special;
		}
		return *this;
	}
	FoodOrder::~FoodOrder() {
		delete[] description;
		description = nullptr;
	}
}