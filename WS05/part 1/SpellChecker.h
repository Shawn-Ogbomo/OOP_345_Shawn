//Filename: spellchecker.h
//Name:	Shawn Ogbomo
// Student #022609127
// date: 02/19/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#ifndef SDDS_SPELLCHECKER_H_
#define SDDS_SPELLCHECKER_H_
#include <string>
#include <array>
namespace sdds {
	class SpellChecker {
	public:
		explicit SpellChecker(const char* filename);
		void operator()(std::string& text);
	private:
		std::array<std::string, 6> m_badWords;
		std::array<std::string, 6> m_goodWords;
	};
}
#endif//!SDDS_SPELLCHECKER_H