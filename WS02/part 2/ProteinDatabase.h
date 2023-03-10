//Filename: ProteinDatabase.h
//Name:	Shawn Ogbomo
// Student #022609127
// date: 01/29/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#ifndef SDDS_PROTEINDATABASE_H_
#define SDDS_PROTEINDATABASE_H_
namespace sdds {
	class  ProteinDatabase {
	public:
		ProteinDatabase();
		ProteinDatabase(const char* file_name);
		ProteinDatabase(const ProteinDatabase& p);
		ProteinDatabase(ProteinDatabase&& p);
		~ProteinDatabase();
		size_t size();
		ProteinDatabase& operator=(ProteinDatabase&& right);
		std::string operator[](size_t index);
		ProteinDatabase& operator= (const ProteinDatabase& right);
	private:
		std::string* elements{};
		int element_count{};
	};
}
#endif//!SDDS_PROTEINDATABASE_H