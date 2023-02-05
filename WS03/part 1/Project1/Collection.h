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
	template <typename T, int CAPACITY = 20>
	class Collection {
	public:
		Collection() :dummy{}, elements{}, element_count{}{}
		unsigned size() { return element_count; }const
			void display(std::ostream& os = std::cout) {
			os << "----------------------" << "\n" <<
				"| Collection Content |" << "\n" <<
				"----------------------" << "\n";
			for (int i = 0; i < element_count; ++i) {
				os << elements[i] << "\n";
			}
			std::cout << "----------------------" << "\n";
		} const
			bool add(const T& item) {
			if (element_count < CAPACITY) {
				elements[element_count] = item;
				++element_count;
				return true;
			}
			return false;
		}

		T& operator[](int index) {
			if (index  < 0 || index >(element_count - 1)) {
				return dummy;
			}
			return elements[index];
		}
	private:
		T dummy;
		T elements[CAPACITY];
		unsigned element_count;
	};
}
#endif//!SDDS_COLLECTION_H