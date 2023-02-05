//Filename: pair.h
//Name:	Shawn Ogbomo
// Student #022609127
// date: 02/04/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#ifndef SDDS_PAIR_H_
#define SDDS_PAIR_H_
namespace sdds {
	class Pair {
	public:
		const std::string& getKey() { return m_key; }
		const std::string& getValue() { return m_value; }
		Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value }{};

		// TODO: Add here the missing prototypes for the members
		//           that are necessary if this class is to be used
		//           with the template classes described below.
		//       Implement them in the Pair.cpp file.
		Pair();
	private:
		std::string m_key{};
		std::string m_value{};
	};
	std::ostream& operator<< (std::ostream& os, Pair& p);
}

#endif//!SDDS_PAIR_H