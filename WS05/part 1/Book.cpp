#include <algorithm>
#include <iostream>
#include <ctype.h>
#include <stdlib.h>
#include "Book.h"
namespace sdds {
	Book::Book() = default;

	Book::Book(const std::string& strBook) {
		static int pos = 1;
		for (unsigned i = 0; i < strBook.size(); ++i) {
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
	const size_t& sdds::Book::year() const {
		return yr;
	}
	double& sdds::Book::price() {
		return cost;
	}
}