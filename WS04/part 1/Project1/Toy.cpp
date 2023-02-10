//Filename: Toy.cpp
//Name:	Shawn Ogbomo
// Student #022609127
// date: 02/09/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include "Toy.h"
sdds::Toy::Toy()
	:order_id{},
	name{},
	amount{},
	price{},
	hst{} {
}

sdds::Toy::Toy(const std::string& toy)
	:order_id{},
	name{},
	amount{},
	price{},
	hst{}  {
	std::string id;
	std::string qty;
	std::string total;
	for (auto i = 0; i < toy.size(); ++i) {
		switch (toy[i]) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '.':
		{
			auto found = toy.find(':', i);
			if (i < max_id_size) {
				id += toy[i];
			}
			else if (found != std::string::npos) {
				while (i < found && !isspace(toy[i])) {
					qty += toy[i];
					++i;
				}
			}
			else {
				total += toy[i];
			}
			break;
		}
		default:
			if (isalpha(toy[i])) {
				std::string s;
				while (isalpha(toy[i]) || isspace(toy[i]))
				{
					s += toy[i];
					++i;
				}
				name = s;
				break;
			}
		}
	}
	static constexpr double harmonized_sales_tax = .13;
	order_id = std::stoi(id);
	amount = std::stoi(qty);
	price = std::stod(total);
	hst = (price + (harmonized_sales_tax * price));
}

void sdds::Toy::update(int numItems) {
	amount = numItems;
	return;
}