//Filename: Collection.h
//Name:	Shawn Ogbomo
// Student #022609127
// date: 02/19/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
//#include <functional>
#ifndef SDDS_COLLECTION_H_
#define SDDS_COLLECTION_H_
namespace sdds {
	template<typename T>
	class Collection {
	public:
		explicit Collection(const std::string& name) :label{ name } {}
		Collection(const Collection&) = delete;
		Collection& operator= (const Collection&) = delete;
		~Collection() {
			delete[] items;
		}
		size_t size()const {
			return capacity;
		}
		const std::string& name() const {
			return label;
		}
		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			fcnptr = observer;
		}
		Collection<T>& operator+=(const T& item) {
			if (!capacity) {
				items = new T[1];
				items[capacity] = item;
				++capacity;
				return *this;
			}

			for (unsigned i = 0; i < capacity; ++i)
				if (items[i].title() == item.title()) {
					return *this;
				}

			auto* temp = new T[capacity];
			//copy everything from items into temp
			for (unsigned i = 0; i < capacity; ++i) {
				temp[i] = items[i];
			}
			//delete items
			delete[] items;

			//create another items array with updated size
			items = new T[capacity + 1];
			// copy everything back
			for (unsigned i = 0; i < capacity; ++i) {
				items[i] = temp[i];
			}
			//delete temp
			delete[] temp;
			//add the item to items
			//increase the capacity by 1
			++capacity;
			//try minus 1 capacity so you dont go into the terminating byte
			items[capacity - 1] = item;
			if (fcnptr) {
				fcnptr(*this, item);
			}
			return *this;
		}
	private:
		std::string label{};
		T* items{};
		unsigned capacity{};
		void(*fcnptr)(const Collection<T>&, const T&) {};
	};
	//std::ostream& operator << (std::ostream& os, const Collection& c);
}
#endif//!SDDS_COLLECTION_H