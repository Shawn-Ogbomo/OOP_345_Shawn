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
#include <vector>
namespace sdds {
	class SpellChecker {
	public:
		class Bad_File_Name {
		public:
			explicit Bad_File_Name(const std::string& err);
			std::string what() const;
		private:
			std::string error_msg{};
		};
		explicit SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
		void update_word_count(const std::string& w);
	private:
		std::array<std::string, 6> m_badWords;
		std::array<std::string, 6> m_goodWords;
		std::vector<std::string> replaced_words;
	};
}
#endif//!SDDS_SPELLCHECKER_H