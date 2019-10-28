#include <string>
#include <iostream>
#include <vector>
#include <cctype>
#include "ex07.h"

using namespace std;

namespace Library
{
    //--------------------------------------------------------------------------------
    //Utils
    //--------------------------------------------------------------------------------

    class InvalidFormatException {};

    bool isbn_is_correct(const string& isbn) {
        const size_t LEN = 13;
        if (isbn.size() != LEN) {
            return false;
        }
        for (size_t i = 0; i < LEN; i++) {
            switch (i) {
            case 3: case 7: case 11:
                if (isbn[i] != '-') {
                    return false;
                }
                break;
            case 12:
                if (!isalnum(isbn[i])) {
                    return false;
                }
                break;
            default:
                if (!isdigit(isbn[i])) {
                    return false;
                }
                break;
            }
        }
        return true;
    }

    bool date_is_correct(Date d) {
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
        f_name = name;
        f_author = author;
        if (date_is_correct(date_of_publishing)) {
            f_date_of_publishing = date_of_publishing;
        }
        else {
            f_date_of_publishing = Date();
        }
        if (isbn_is_correct(isbn)) {
            f_isbn = isbn;
        }
        else {
            f_isbn = "000-000-000-0";
            throw InvalidFormatException();
        }
    }

    Book::Book(string isbn, string name, string author, Date date_of_publishing) {
        try {
            init(isbn, name, author, date_of_publishing);
        }
        catch (InvalidFormatException e) {
            cout << "Format error in ISBN:" << isbn << ". Object with default ISBN has been created." << endl;
        }
    }

    Book::Book(string isbn, string name, string author, Date date_of_publishing, Genre genre) {
        try {
            init(isbn, name, author, date_of_publishing);
        }
        catch (InvalidFormatException e) {
            cout << "Format error in ISBN:" << isbn << ". Object with default ISBN has been created." << endl;
        }
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

	string Book::issued_to() const {
		return f_issued_to == "" ? "Not issued" : f_issued_to;
	}

    ostream& operator<<(ostream& out, Book b) {
        return out
            << "ISBN: " << b.isbn() << ", "
            << b.author() << ": \"" << b.name() << "\", "
            << b.date_of_publishing() << ", "
            << b.genre()
			<< b.issued_to() << flush;
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
		default:
			gs = "undefined genre";
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
    Book b("123-456-789a-x", "The Adventures of Sherlock Holmes",
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
