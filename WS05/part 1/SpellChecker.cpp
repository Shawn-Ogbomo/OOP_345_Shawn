//Filename: spellchecker.cpp
//Name:	Shawn Ogbomo
// Student #022609127
// date: 02/19/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include <fstream>
#include "SpellChecker.h"
namespace sdds {
	SpellChecker::SpellChecker(const char* filename) {
		std::ifstream ifs{ filename };
		if (!ifs) {
			throw std::string{ "Bad file name!" };
		}
		for (auto i = 0; ifs >> m_badWords[i] >> m_goodWords[i]; ++i) {
			if (ifs.eof()) {
				break;
			}
		}
	}
	void SpellChecker::operator()(std::string& text) {
		//count how many times a bad word has been replaced...
	}
}