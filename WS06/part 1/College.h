//Filename: College.h
//Name:	Shawn Ogbomo
// Student #022609127
// date: 03/03/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#ifndef SDDS_COLLEGE_H
#define SDDS_COLLEGE_H
#include <vector>
#include <list>
#include "Person.h"
namespace sdds {
	class College {
	public:
		College();
		~College();
		College& operator +=(Person* thePerson);
		College(const College& c) = delete;
		College& operator =(const College& right) = delete;
		void display(std::ostream& out) const;
		//template<typename T>
		/*	void select(const T& test, std::list<const Person*>& persons) {
			}*/
	private:
		std::vector<Person*> m_persons;
	};
}

#endif//!SDDS_COLLEGE_H