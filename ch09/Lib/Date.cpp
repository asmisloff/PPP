#include "pch.h"
#include "Date.h"

namespace ExLib {
	Date::Date() {
		_year = 1901;
		_month = Jan;
		_day = 1;
	}

	Date::Date(int year, Month month, int day) : _year(year), _month(month), _day(day) {
		if (!isValidDate(*this)) {
			throw InvalidDate();
		}
	}

	Date Date::today() {
		return Date();
	}

	bool Date::isValidDate(const Date& d) {
		if (d._day <= 0) return false;
		if (d._month < Jan || d._month > Dec) return false;
		int daysInMonth = 31;
		
		switch (d._month) {
		case Feb:
			daysInMonth = isLeapYear(d._year) ? 29 : 28;
			break;
		case Apr: case Jun: case Sept: case Nov:
			daysInMonth = 30;
			break;
		}
		if (d._day > daysInMonth) return false;

		return true;
	}

	bool Date::isLeapYear(int year) {
		return false;
	}

	string toString(Month m) {
		static vector<string> mm = {"Jan", "Feb", "Mar", "Apr", "May" "Jun", "July", "Sept", "Oct", "Nov", "Dec"};
		return mm[m - 1];
	}

	ostream & operator<<(ostream & out, Date d) {
		return out << d.year() << "-" << toString(d.month()) << "-" << d.day();
	}
}