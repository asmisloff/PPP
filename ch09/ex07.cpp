#include <string>
#include <iostream>
#include <vector>
#include <cctype>
#include "ex07.h"
#include "patron.h"

using namespace std;

namespace Library
{
	//--------------------------------------------------------------------------------
	//Utils
	//--------------------------------------------------------------------------------

	class InvalidFormatException {};

	void read_digits(const string& s, size_t& pos, char delimiter = '-') {
		char c = s[pos];
		while (isdigit(c)) {
			c = s[++pos];
		}
		if (c == delimiter) return;
		else throw InvalidFormatException();
	}

	bool is_valid_isbn(const string& s) {
		size_t pos = -1;
		for (int i = 0; i < 3; i++) {
			try {
				read_digits(s, ++pos);
			}
			catch (InvalidFormatException) {
				return false;
			}
		}
		if (pos == s.size() - 2 && isalnum(s[pos + 1])) {
			return true;
		}
		else {
			return false;
		}
	}

	bool is_correct_date(Date d) {
		//TODO: 
		return true;
	}

	//--------------------------------------------------------------------------------
	//Date
	//--------------------------------------------------------------------------------

	Date::Date() : y(2000), m(Month::jan), d(1) {}

	Date::Date(int year, Month month, int day) : y(year), m(month), d(day) {}

	int Date::year() const {
		return y;
	}

	Month Date::month() const {
		return m;
	}

	int Date::day() const {
		return d;
	}

	string Date::to_string() const {
		return std::to_string(y) + "-" + std::to_string(m) + "-" + std::to_string(d);
	}

	void Date::set_year(int y) {
		this->y = y;
	}

	void Date::set_month(Month m) {
		this->m = m;
	}

	void Date::set_day(int d) {
		this->d = d;
	}

	ostream& operator<<(ostream& os, const Date& d)
	{
		return os << d.year() << '-' << d.month() << '-' << d.day();
	}

	//--------------------------------------------------------------------------------
	//Book
	//--------------------------------------------------------------------------------

	void Book::init(string isbn, string name, string author, Date date_of_publishing) {
		if (is_valid_isbn(isbn)) {
			f_isbn = isbn;
		}
		else {
			throw InvalidFormatException();
		}
		f_name = name;
		f_author = author;
		if (is_correct_date(date_of_publishing)) {
			f_date_of_publishing = date_of_publishing;
		}
	}

	Book::Book(string isbn, string name, string author, Date date_of_publishing) {
		init(isbn, name, author, date_of_publishing);
	}

	Book::Book(string isbn, string name, string author, Date date_of_publishing, Genre genre) {
		init(isbn, name, author, date_of_publishing);
		f_genre = genre;
	}

	const string& Book::isbn() const
	{
		return f_isbn;
	}

	string Book::name() const
	{
		return f_name;
	}

	string Book::author() const
	{
		return f_author;
	}

	Genre Book::genre() const {
		return f_genre;
	}
	
	Date Book::date_of_publishing() const
	{
		return f_date_of_publishing;
	}

	ostream& operator<<(ostream& out, Book b) {
		return out
			<< "ISBN: " << b.isbn() << ", "
			<< b.author() << ": \"" << b.name() << "\", "
			<< b.date_of_publishing() << ", "
			<< b.genre() << flush;
	}

	ostream & operator<<(ostream& out, Genre g) {
		string gs;
		switch (g) {
		case Genre::science_fiction:
			gs = "Science Fiction";
			break;
		case Genre::prose:
			gs = "Prose";
			break;
		case Genre::periodicals:
			gs = "Periodicals";
			break;
		case Genre::children_lit:
			gs = "Children's Literature";
			break;
		case Genre::biography:
			gs = "Biography";
			break;
		}
		return out << gs;
	}

	bool operator==(const Book& self, const Book& other) {
		auto cmp = [](const char& c1, const char& c2) -> bool {
			return tolower(c1) == tolower(c2);
		};
		const string& s1 = self.isbn();
		const string& s2 = other.isbn();
		return equal(s1.begin(), s1.end(), s2.begin(), cmp);
	}

	bool operator!=(const Book& self, const Book& other) {
		return !(self == other);
	}
}
//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------

using namespace Library;

int main() {
    Date d(2019, Month::oct, 6);
	Book b("123-456-789-x", "The Adventures of Sherlock Holmes",
		   "Arthur Conan Doyle", Date(1892, Month::oct, 14), Genre::prose);
	Book B("123-456-789-X", "The Adventures of Sherlock Holmes",
		   "Arthur Conan Doyle", Date(1892, Month::oct, 14), Genre::prose);
	cout << b << endl;
	cout << "B == b --> " << (B == b ? "true" : "false") << endl;
	cout << "B != b --> " << (B != b ? "true" : "false") << endl;

	Patron mrSmith("Smith", 1);
	mrSmith.set_fee(100);
	cout << mrSmith << endl;
	mrSmith.pais_fee();
	cout << mrSmith << endl;
}
