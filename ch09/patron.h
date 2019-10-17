#include <string>
#include <iostream>

using namespace std;

namespace Library {
	class Patron {
	private:
		string _name;
		int _id;
		int _fee;
		bool _fee_paid;
	public:
		Patron(string name, int id);
		const string& name() const;
		int id() const;
		int fee() const;
		bool fee_paid() const;
		void set_fee(int fee);
		void pais_fee();
	};

	ostream& operator<< (ostream& out, Patron p);
}