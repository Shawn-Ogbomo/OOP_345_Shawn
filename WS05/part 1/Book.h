//Filename: Book.h
//Name:	Shawn Ogbomo
// Student #022609127
// date: 02/19/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_
#include <string>
namespace sdds {
	enum class Field {
		name = 1, title, nation, price, year, description,
	};
	class Book {
	public:
		Book();
		explicit Book(const std::string& strBook);
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		const std::string& writer() const;
		const std::string& details() const;
		friend std::ostream& operator <<(std::ostream& os, const Book& b);

	private:
		std::string name;
		std::string nation;
		std::string author;
		unsigned yr{};
		double cost{};
		std::string description;
	};
}
#endif//!SDDS_BOOK_H