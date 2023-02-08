//Filename: set.h
//Name:	Shawn Ogbomo
// Student #022609127
// date: 02/04/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#ifndef SDDS_SET_H_
#define SDDS_SET_H_
#include <math.h>
#include "Collection.h"
namespace sdds {
	template<typename T>
	class Set : public Collection<T, 100> {
	public:
		bool add(const T& item) override {
			if (this->element_count < 100) {
				for (unsigned i = 0; i < 100; ++i) {
					if (item == this->elements[i]) {
						return false;
					}
				}
				this->elements[this->element_count] = item;
				++this->element_count;
				return true;
			}
			return false;
		}
	private:
	};
	template<>
	bool sdds::Set<double>::add(const double& item) {
		if (this->element_count < 100) {
			constexpr double threshhold = 0.01;
			for (unsigned i = 0; i < 100; ++i) {
				if (std::fabs(item - elements[i]) <= threshhold) {
					return false;
				}
			}
			this->elements[this->element_count] = item;
			++this->element_count;
			return true;
		}
		return false;
	}
}
#endif//!SDDS_SET_H