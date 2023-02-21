//Filename: Movie.cpp
//Name:	Shawn Ogbomo
// Student #022609127
// date: 02/19/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include "Movie.h"
#include "Book.h"
namespace sdds {
	Movie::Movie() = default;

	Movie::Movie(const std::string& strMovie) {
		const unsigned max_size = strMovie.size();
		static int pos = 2;
		for (unsigned i = 0; i < max_size; ++i) {
			switch (strMovie[i]) {
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
			{
				std::string s;
				if (pos == static_cast<int>(sdds::Field::year)) {
					while (isdigit(strMovie[i])) {
						s += strMovie[i];
						++i;
					}
					yr = std::stoi(s);
					pos += static_cast<int>(sdds::Field::title);
				}
				break;
			}
			default:
				if (isalpha(strMovie[i])) {
					std::string internal_s;
					if (pos == static_cast<int>(sdds::Field::title)) {
						while (isalpha(strMovie[i]) || isspace(strMovie[i]) || strMovie[i] == ':') {
							internal_s += strMovie[i];
							++i;
						}
						name = internal_s;
						pos += static_cast<int>(sdds::Field::title);
					}
					else if (pos == static_cast<int>(sdds::Field::description)) {
						while ((isalpha(strMovie[i]) || isspace(strMovie[i]) || ispunct(strMovie[i])) && (pos == static_cast<int>(sdds::Field::description))) {
							internal_s += strMovie[i];
							++i;
						}
						details = internal_s;
					}
					while (isspace(internal_s.back())) {
						internal_s.pop_back();
					}
					if (pos >= static_cast<int>(sdds::Field::description)) {
						pos = 1;
					}
					break;
				}
			}
		}
	}
	const std::string& Movie::title() const {
		return name;
	}
	int Movie::year() const {
		return yr;
	}
	const std::string& Movie::description() const {
		return details;
	}
	std::ostream& operator<<(std::ostream& os, const Movie& m) {
		os << m.title() << "     " << m.year() << "     " << m.description();
		return os;
	}
}