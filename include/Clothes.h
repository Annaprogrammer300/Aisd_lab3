#ifndef SORT_INCLUDE_Clothes_H
#define SORT_INCLUDE_Clothes_H

#include <iostream>
#include <string>
#include <vector>

class Clothes {
private:
	std::string _name;
	size_t _price;
public:
	Clothes() : _name(""), _price(0) {}
	Clothes(std::string name, size_t weight) :_name(name), _price(weight) {}

	Clothes(const Clothes& other) {
		_name = other._name;
		_price = other._price;
	}


	std::string get_name() const {
		return _name;
	}

	size_t get_price() const {
		return _price;
	}

	bool operator==(const Clothes& other) const {
		return ((_name == other._name) && (_price == other._price));
	}

	bool operator<(const Clothes& other) const {
		return ((_name < other._name) || ((_name == other._name) && (_price < other._price)));
	}

	bool operator>=(const Clothes& other) const {
		return ((_name >= other._name) || ((_name == other._name) && (_price >= other._price)));
	}

	bool operator<=(const Clothes& other) const {
		return ((_name <= other._name) || ((_name == other._name) && (_price <= other._price)));
	}

	bool operator>(const Clothes& other) const {
		return ((_name > other._name) || ((_name == other._name) && (_price > other._price)));
	}
};

std::ostream& operator<<(std::ostream& stream, const Clothes& Clothes) {
	stream << "[" << Clothes.get_name() << ", " << Clothes.get_price() << "]";
	return stream;
}

std::ostream& operator<<(std::ostream& os, std::vector<Clothes>& list) {
	for (const Clothes& Clothes : list) {
		os << Clothes << std::endl;
	}
	os << std::endl;
	return os;
}


#endif