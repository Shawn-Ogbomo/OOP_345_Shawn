//Filename: spellchecker.h
//Name:	Shawn Ogbomo
// Student #022609127
// date: 02/19/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include <functional>
#ifndef SDDS_COLLECTION_H_
#define SDDS_COLLECTION_H_
namespace sdds {
	template<typename T>
	class Collection {
	public:
		explicit Collection(const std::string& name) :name{ name } {}
		Collection(const Collection&) = delete;
		Collection& operator= (const Collection&) = delete;
		~Collection() {
			delete[] items;
		}
		const std::string& name() const {
			return this.name;
		}
	private:
		std::string label{};
		T* items{};
		unsigned size{};
		void(*fcnptr)(const Collection<T>& left, const Collection<T>& right);
		//function pointer with type- aliasing
		using observer = std::function<void(const Collection<T>&, const Collection <T>&)>;
	};
	//std::ostream& operator << (std::ostream& os, const Collection& c);
}
#endif//!SDDS_COLLECTION_H