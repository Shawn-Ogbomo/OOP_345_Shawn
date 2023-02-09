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
			id += toy[i];
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
			}

			break;
		}
	}
}

void sdds::Toy::update(int numItems) {
	amount = numItems;
	return;
}