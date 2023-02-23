//Filename: Util.cpp
//Name:	Shawn Ogbomo
// Student #022609127
// date: 02/19/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include "Util.h"

int Util::count(const std::array<std::string, 6>& words, const std::string& word) {
	auto num_words = 0;
	if (!words.empty()) {
		for (const auto& internal_word : words) {
			if (word == internal_word) {
				++num_words;
			}
		}
	}
	return num_words;
}