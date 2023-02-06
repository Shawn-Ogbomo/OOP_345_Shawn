//Filename: Collection.h
//Name:	Shawn Ogbomo
// Student #022609127
// date: 02/04/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#ifndef SDDS_COLLECTION_H_
#define SDDS_COLLECTION_H_
#include <iostream>
#include "Pair.h"
namespace sdds {
	template <typename T, unsigned CAPACITY = 20>
	class Collection {
	public:
		Collection() :dummy{}, elements{}, element_count{}{}
		void display(std::ostream& os = std::cout) {
			os << "----------------------" << "\n" <<
				"| Collection Content |" << "\n" <<
				"----------------------" << "\n";
			for (unsigned i = 0; i < CAPACITY; ++i) {
				if (i < element_count)
					os << elements[i] << "\n";
			}
			std::cout << "----------------------" << "\n";
		}
		unsigned size()const { return element_count; }
		bool add(const T& item) {
			if (element_count < CAPACITY) {
				elements[element_count] = item;
				++element_count;
				return true;
			}
			return false;
		}
		T& operator[](unsigned index) {
			if (index > (element_count - 1)) {
				return dummy;
			}
			return elements[index];
		}
	private:
		T dummy;
		T elements[CAPACITY];
		unsigned element_count;
	};
	template<>
	sdds::Collection<Pair, 100>::Collection() :dummy{ "No key","No Value" }, elements{}, element_count{}{}
}
#endif//!SDDS_COLLECTION_H