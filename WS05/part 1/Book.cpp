//Filename: Book.cpp
//Name:	Shawn Ogbomo
// Student #022609127
// date: 02/19/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include <algorithm>
#include <iostream>
#include <ctype.h>
#include <stdlib.h>
#include <iomanip>
#include "Book.h"
namespace sdds {
	Book::Book() = default;

	Book::Book(const std::string& strBook) {
		static int pos = 1;
		const unsigned max_size = strBook.size();
		for (unsigned i = 0; i < max_size; ++i) {
			switch (strBook[i]) {
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
				std::string s;
				if (pos == static_cast<int>(sdds::Field::price)) {
					while (isdigit(strBook[i]) || strBook[i] == '.') {
						s += strBook[i];
						++i;
					}
					cost = std::stod(s);
				}

				else if (pos == static_cast<int>(sdds::Field::year)) {
					while (isdigit(strBook[i])) {
						s += strBook[i];
						++i;
					}
					yr = std::stoi(s);
				}
				++pos;
				break;
			}
			default:
				if (isalpha(strBook[i])) {
					std::string internal_s;
					while ((isalpha(strBook[i]) || isspace(strBook[i]) || strBook[i] == '.') && pos <= static_cast<int>(sdds::Field::nation)) {
						internal_s += strBook[i];
						++i;
					}
					while ((isalpha(strBook[i]) || isspace(strBook[i]) || ispunct(strBook[i])) && (pos == static_cast<int>(sdds::Field::description))) {
						internal_s += strBook[i];
						++i;
					}
					while (isspace(internal_s.back())) {
						internal_s.pop_back();
					}
					if (pos == static_cast<int>(sdds::Field::name)) {
						author = internal_s;
					}
					else if (pos == static_cast<int>(sdds::Field::title)) {
						name = internal_s;
					}
					else if (pos == static_cast<int>(sdds::Field::nation)) {
						nation = internal_s;
					}
					else if (pos == static_cast<int>(sdds::Field::description)) {
						description = internal_s;
					}
					++pos;
					if (pos > static_cast<int>(sdds::Field::description)) {
						pos = 1;
					}
					break;
				}
			}
		}
	}
	const std::string& sdds::Book::title() const {
		return name;
	}
	const std::string& sdds::Book::country() const {
		return nation;
	}
	const std::string& Book::writer() const {
		return author;
	}
	const std::string& Book::details() const {
		return description;
	}
	const size_t& sdds::Book::year() const {
		return yr;
	}
	double& sdds::Book::price() {
		return cost;
	}

	std::ostream& operator<<(std::ostream& os, const Book& b) {
		return os << std::setw(20) << b.writer() << " |" << std::right << std::setw(23) << b.title() << " |" << std::setw(6) << b.country() << " |" << std::setw(5) << b.year() << " |" << std::setw(6) << std::setprecision(2) << std::fixed << b.cost << " | " << b.details() << "\n";
	}
}