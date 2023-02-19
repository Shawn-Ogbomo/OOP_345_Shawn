#include <algorithm>
#include <ctype.h>
#include "Book.h"
namespace sdds {
	Book::Book() = default;

	Book::Book(const std::string& strBook) {
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
				break;
			}
			default:
				if (isalpha(strBook[i])) {
					std::string s;
					static int count = 1;
					while ((isalpha(strBook[i]) || isspace(strBook[i])) && count <= static_cast<int>(sdds::Field::nation)) {
						s += strBook[i];
						++i;
					}
					while (isalpha(strBook[i]) || isspace(strBook[i]) && count == static_cast<int>(sdds::Field::description)) {
						s += strBook[i];
						++i;
					}
					while (isspace(s.back())) {
						s.pop_back();
					}
					if (count == static_cast<int>(sdds::Field::name)) {
						author = s;
					}
					else if (count == static_cast<int>(sdds::Field::title)) {
						name = s;
					}
					else if (count == static_cast<int>(sdds::Field::nation)) {
						nation = s;
					}
					else if (count == static_cast<int>(sdds::Field::description)) {
						description = s;
					}
					++count;
				}
				break;
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