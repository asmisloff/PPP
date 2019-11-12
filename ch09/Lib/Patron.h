#pragma once
#include <string>

using namespace std;

namespace ExLib {
	class Patron
	{
	public:
		Patron(int id, string name, int fee);
		Patron();

		int id() const {
			return _id;
		}

		const string& name() const {
			return _name;
		}

		int fee() const {
			return _fee;
		}

		bool feePaid() const {
			return _feePaid;
		}

		int setFee(int fee) {
			_fee = fee;
			return _fee;
		}

		friend bool operator==(const Patron& self, const Patron& other);

	private:
		int _id;
		string _name;
		int _fee;
		bool _feePaid;
	};
}

