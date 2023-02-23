//Filename: Collection.h
//Name:	Shawn Ogbomo
// Student #022609127
// date: 02/19/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include <iostream>
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
			for (unsigned i = 0; i < capacity; ++i) {
				temp[i] = items[i];
			}
			delete[] items;

			items = new T[capacity + 1];
			for (unsigned i = 0; i < capacity; ++i) {
				items[i] = temp[i];
			}
			delete[] temp;
			++capacity;
			items[capacity - 1] = item;
			if (fcnptr) {
				fcnptr(*this, item);
			}
			return *this;
		}
		friend std::ostream& operator<<(std::ostream& os, const Collection<T>& c) {
			for (unsigned i = 0; i < c.capacity; ++i) {
				std::cout << c.items[i];
			}
			return os;
		}
		T& operator[](size_t idx) const {
			if (capacity <= idx) {
				throw std::out_of_range{ "** EXCEPTION: Bad index [" + std::to_string(idx) + "] Collection has[" + std::to_string(idx) + "]items." };
			}
			return items[idx];
		}
		T* operator[](const std::string& title) const {
			for (unsigned i = 0; i < capacity; ++i) {
				if (items[i].title() == title) {
					return &items[i];
				}
			}
			return nullptr;
		}
	private:
		std::string label{};
		T* items{};
		unsigned capacity{};
		void(*fcnptr)(const Collection<T>&, const T&) {};
	};
}
#endif//!SDDS_COLLECTION_H