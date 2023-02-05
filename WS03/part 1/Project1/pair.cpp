#include <string>
#include <iostream>
#include <iomanip>
#include "Pair.h"
namespace sdds {
	std::ostream& operator<<(std::ostream& os, Pair& p) {
		return os << std::setw(20) << p.getKey() << ":" << " " << p.getValue();
	}
	Pair::Pair() : m_key{}, m_value{}{
	}
}