// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel
// 2021/01/19 - Chris
// 2021/02/12 - Cornel

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Book.h"
#include "Book.h"

using namespace sdds;

enum AppErrors
{
	CannotOpenFile = 1, // An input file cannot be opened
	BadArgumentCount = 2, // The application didn't receive anough parameters
};

// ws books.txt
int main(int argc, char** argv) {
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// get the books
	sdds::Book library[7];
	if (argc == 2) {
		// TODO: load the collection of books from the file "argv[1]".
		//       - read one line at a time, and pass it to the Book constructor
		//       - store each book read into the array "library"
		//       - lines that start with "#" are considered comments and should be ignored
		//       - if the file cannot be open, print a message to standard error console and
		//                exit from application with error code "AppErrors::CannotOpenFile"
		std::ifstream ifs{ argv[1] };
		if (!ifs) {
			std::cerr << "The file: " << argv[1] << "does not exist...\n";
			exit(AppErrors::CannotOpenFile);
		}
		long long valid_pos{};
		while (ifs) {
			std::string s;
			std::getline(ifs, s);
			if (ifs.peek() != '#') {
				valid_pos = ifs.tellg();
				break;
			}
		}

		ifs.seekg(valid_pos);
		for (auto i = 0; !ifs.eof(); ++i) {
			std::string internal_s;
			std::getline(ifs, internal_s);
			library[i] = Book{ internal_s };
		}
	}
	else {
		std::cerr << "ERROR: Incorrect number of arguments.\n";
		exit(AppErrors::BadArgumentCount);
	}

	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	//// TODO: create a lambda expression that fixes the price of a book accoding to the rules
	////       - the expression should receive a single parameter of type "Book&"
	////       - if the book was published in US, multiply the price with "usdToCadRate"
	////            and save the new price in the book object
	////       - if the book was published in UK between 1990 and 1999 (inclussive),
	////            multiply the price with "gbpToCadRate" and save the new price in the book object
	const std::string america = "US";
	const std::string united_kingdom = "UK";
	auto update_price{
		[&america,&united_kingdom,usdToCadRate,gbpToCadRate](Book& b) {
		if (b.country() == america) {
			return (b.price() * usdToCadRate);
		}
		else if (b.country() == united_kingdom && (b.year() >= 1990 && b.year() <= 1999)) {
			return  (b.price() * gbpToCadRate);
		}
		return b.price();
	}
	};

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";
	//// TODO: iterate over the library and print each book to the screen
	for (const auto& book : library) {
		std::cout << book;
	}
	//std::cout << "-----------------------------------------\n\n";

	//// TODO: iterate over the library and update the price of each book
	////         using the lambda defined above.

	for (auto& target : library) {
		target.price() = update_price(target);
	}
	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	//// TODO: iterate over the library and print each book to the screen
	for (const auto& updated_book : library) {
		std::cout << updated_book;
	}
	std::cout << "-----------------------------------------\n";

	return 0;
}