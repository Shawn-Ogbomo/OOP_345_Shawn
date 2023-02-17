//Filename: ConfirmOrder.cpp
//Name:	Shawn Ogbomo
// Student #022609127
// date: 02/09/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include "ConfirmOrder.h"
namespace sdds {
	ConfirmOrder::ConfirmOrder() = default;

	ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy) {
		for (unsigned i = 0; i < count; ++i) {
			if (toys[i] == &toy) {
				return *this;
			}
		}

		++count;
		if (count > 1) {
			const auto** temp = new const Toy * [count - 1];
			for (unsigned i = 0; i < count - 1; ++i) {
				temp[i] = new const Toy{ *toys[i] };
			}

			for (unsigned j = 0; j < count - 1; ++j) {
				delete toys[j];
			}

			delete[] toys;
			toys = new const Toy * [count];

			for (unsigned k = 0; k < count - 1; ++k) {
				toys[k] = new const Toy{ *temp[k] };
			}

			for (unsigned internal_k = 0; internal_k < count - 1; ++internal_k) {
				delete temp[internal_k];
			}

			delete[] temp;
			toys[count - 1] = &toy;
			//toys[count - 1] = new const Toy{ toy };
			return *this;
		}

		toys = new const Toy * [count];
		toys[count - 1] = &toy;
		//toys[count - 1] = new const Toy{ toy };
		return *this;
	}
	ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy) {
		bool found_toy{};
		for (unsigned i = 0; i < count; ++i) {
			if (toys[i] == &toy) {
				toys[i] = nullptr;
				found_toy = true;
				break;
			}
		}

		if (found_toy) {
			const auto** temp = new const Toy * [count - 1];
			for (unsigned j = 0, k = 0; j < count; ++j) {
				if (toys[j]) {
					temp[k] = new const Toy{ *toys[j] };
					++k;
				}
			}

			for (unsigned internal_i = 0; internal_i < count; ++internal_i) {
				delete toys[internal_i];
			}

			delete[] toys;
			--count;
			toys = new const Toy * [count];

			for (unsigned internal_j = 0; internal_j < count; ++internal_j) {
				toys[internal_j] = new const Toy{ *temp[internal_j] };
			}

			for (unsigned internal_k = 0; internal_k < count; ++internal_k) {
				delete temp[internal_k];
			}
			delete[] temp;
			return *this;
		}
		return*this;
	}

	std::ostream& operator<<(std::ostream& os, const ConfirmOrder& c) {
		if (!c.count) {
			return os << "--------------------------\n" << "Confirmations to Send\n"
				<< "--------------------------\n" << "There are no confirmations to send!\n"
				<< "--------------------------\n";
		}
		os << "--------------------------\n" << "Confirmations to Send\n"
			<< "--------------------------\n";
		for (auto i = 0u; i < c.count; ++i) {
			os << *c.toys[i];
		}
		os << "--------------------------";
		return os;
	}
}