#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace ExLib {

	enum Month { Jan = 1, Feb, Mar, Apr, May, Jun, July, Aug, Sept, Nov, Dec };

	class InvalidDate {};

	class Date
	{
	public:
		Date();
		Date(int year, Month month, int day);
		
		int year() const {
			return _year;
		}

		Month month() const {
			return _month;
		}

		int day() const {
			return _day;
		}

		static Date today();

		friend ostream& operator<<(ostream& out, Date d);

	private:
		int _year;
		Month _month;
		int _day;
		static bool isValidDate(const Date& d);
		static bool isLeapYear(int year);
	};
}