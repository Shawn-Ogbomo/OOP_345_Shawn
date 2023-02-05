//Filename: Collection.h
//Name:	Shawn Ogbomo
// Student #022609127
// date: 02/04/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#ifndef SDDS_COLLECTION_H_
#define SDDS_COLLECTION_H_
namespace sdds {
	template <typename T, unsigned capacity>
	class Collection {
	public:
		Collection() :default_element{}, elements{}, element_count{}{}
		unsigned size() { return element_count; }const
			void display(std::ostream& os = std::cout) {
			for (int i = 0; i < element_count; ++i) {
				os << elements[i] << "\n";
			}
		} const
			bool add(const T& item) {
			if (element_count < capacity) {
				elements[element_count] = item;
				++element_count;
				return true;
			}
			return false;
		}
		T& operator[](int index) {
			if (index  < 0 || index >(element_count - 1)) {
				return default_element;
			}
			return elements[index];
		}
	private:
		T default_element;
		T elements[capacity];
		unsigned element_count;
	};
}
#endif//!SDDS_COLLECTION_H