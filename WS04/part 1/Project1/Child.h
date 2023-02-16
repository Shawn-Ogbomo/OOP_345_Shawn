//Filename: Child.h
//Name:	Shawn Ogbomo
// Student #022609127
// date: 02/09/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#ifndef SDDS_CHILD_H_
#define SDDS_CHILD_H_
#include <string>
#include <iostream>
#include "Toy.h"
namespace sdds {
	class Child {
	public:
		Child(const std::string& name, int age, const Toy* toys[], size_t count);
		Child(const Child& c);
		Child(Child&& c) noexcept;
		~Child();
		Child& operator =(Child&& right) noexcept;
		Child& operator = (const Child& right);
		size_t size() const;
	private:
		std::string name;
		int age;
		size_t count;
		const sdds::Toy** toys{};
		friend std::ostream& operator << (std::ostream& os, const Child& c);
	};
}
#endif//!SDDS_CHILD_H