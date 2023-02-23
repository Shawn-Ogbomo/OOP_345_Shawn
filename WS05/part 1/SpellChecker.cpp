//Filename: spellchecker.cpp
//Name:	Shawn Ogbomo
// Student #022609127
// date: 02/19/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include <fstream>
#include <vector>
#include <iomanip>
#include "SpellChecker.h"
#include "Util.h"
namespace sdds {
	SpellChecker::SpellChecker(const char* filename) {
		std::ifstream ifs{ filename };
		if (!ifs) {
			throw Bad_File_Name{ "Bad file name!" };
		}
		for (auto i = 0; ifs >> m_badWords[i] >> m_goodWords[i]; ++i) {
			if (ifs.eof()) {
				break;
			}
		}
	}
	void SpellChecker::operator()(std::string& text) {
		auto pos = 0;
		for (const auto& word : m_badWords) {
			auto found_index = text.find(word);
			if (found_index != std::string::npos) {
				text.replace(found_index, word.size(), m_goodWords[pos]);
				update_word_count(word);
			}
			++pos;
		}
	}

	void SpellChecker::update_word_count(const std::string& w) {
		replaced_words.push_back(w);
	}

	void SpellChecker::showStatistics(std::ostream& out) const {
		out << "Spellchecker Statistics\n";
		for (const auto& word : m_badWords) {
			out << std::right << std::setw(15) << word << ": " << Util::count(replaced_words, word) << " replacements\n";
		}
	}

	SpellChecker::Bad_File_Name::Bad_File_Name(const std::string& err) :error_msg{ err } {
	}
	std::string SpellChecker::Bad_File_Name::what() const {
		return error_msg;
	}
}