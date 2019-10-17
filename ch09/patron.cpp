#include <string>
#include <iostream>
#include "patron.h"

using namespace std;

namespace Library {
	Patron::Patron(string name, int id)
		: _name(name), _id(id), _fee_paid(false) {}

	const string & Patron::name() const {
		return _name;
	}

	int Patron::id() const {
		return _id;
	}

	int Patron::fee() const {
		return _fee;
	}

	bool Patron::fee_paid() const {
		return _fee_paid;
	}

	void Patron::set_fee(int fee) {
		_fee = fee;
	}

	void Patron::pais_fee() {
		_fee_paid = true;
	}
	
	ostream & operator<<(ostream & out, Patron p) {
		return out
			<< p.id() << ": "
			<< p.name()
			<< ". Fee is " << (p.fee_paid() == true ? "paid" : "not paid");
	}
}

//int main() {
//	Library::Patron p("aaasa", 1);
//	cout << p;
//}