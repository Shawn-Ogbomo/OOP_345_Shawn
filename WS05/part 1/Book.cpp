#include "Book.h"
namespace sdds {
	Book::Book() = default;

	Book::Book(const std::string& strBook) {
	}
	const std::string& sdds::Book::title() const {
		return name;
	}
	const std::string& Book::country() const {
		return nation;
	}
	const size_t& Book::year() const {
		return yr;
	}
	double& Book::price() {
		return cost;
	}
}