//Filename: Movie.h
//Name:	Shawn Ogbomo
// Student #022609127
// date: 02/19/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#ifndef SDDS_MOVIE_H_
#define SDDS_MOVIE_H_
#include <string>
#include <fstream>
namespace sdds {
	class Movie {
	public:
		Movie();
		explicit Movie(const std::string& strMovie);
		const std::string& title() const;
		int year() const;
		const std::string& description() const;
		template <typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(details);
		}
	private:
		std::string name;
		int yr{};
		std::string details;
	};
	std::ostream& operator <<(std::ostream& os, const Movie& m);
}
#endif//!SDDS_MOVIE_H