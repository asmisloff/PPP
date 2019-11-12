#include "pch.h"
#include "Patron.h"

namespace ExLib {
	Patron::Patron(int id, string name, int fee) : _id(id), _name(name), _fee(fee), _feePaid(false) {
	}
	Patron::Patron() : _id(0), _name(""), _fee(0) { }
	bool operator==(const Patron & self, const Patron & other) {
		return self.id() == other.id();
	}
}

