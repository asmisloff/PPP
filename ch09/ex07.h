#include <string>
#include "patron.h"

using namespace std;

namespace Library
{
	enum Month {
		jan = 1, feb, mar, apr, may, jun, jul, aug, sept, oct, nov, dec
	};

	enum Genre {
		science_fiction, prose, periodicals, biography, children_lit
	};

	class Date
	{
	public:
		Date();
		Date(int year, Month month, int day);
		int year() const;
		Month month() const;
		int day() const;
		string to_string() const;
		void set_year(int y);
		void set_month(Month m);
		void set_day(int d);

	private:
		int y;
		Month m;
		int d;
	};

	ostream& operator<<(ostream& os, const Date& d);

	class Book
	{
	private:
		string f_isbn;
		string f_name;
		string f_author;
		Date f_date_of_publishing;
		void init(string isbn, string name, string author, Date date_of_publishing);
		Genre f_genre;
		string f_issued_to;

	public:
		Book(string isbn, string name, string author, Date date_of_publishing);
		Book(string isbn, string name, string author, Date date_of_publishing, Genre genre);
		const string& isbn() const;
		string name() const;
		string author() const;
		Genre genre() const;
		Date date_of_publishing() const;
		string issued_to() const;
	};

	ostream& operator <<(ostream&, Book);
	ostream& operator <<(ostream&, Genre);
	bool operator==(const Book&, const Book&);
	bool operator!=(const Book&, const Book&);
}
