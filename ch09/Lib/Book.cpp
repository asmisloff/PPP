#include "pch.h"
#include "Book.h"

namespace ExLib {

	bool isbnIsCorrect(const string& isbn) {
		/*ISBN must match the pattern: ddd-ddd-ddd-x.
		  Here d is a digit and x is a digit or a letter.*/
		const size_t len = 13;
		if (isbn.size() != len) { return false; }

		for (size_t i = 0; i < len; i++) {
			switch (i) {
			case 3: case 7: case 11:
				if (isbn[i] != '-') { return false; }
				break;
			case 12:
				if (!isalnum(isbn[i])) { return false; }
				break;
			default:
				if (!isdigit(isbn[i])) { return false; }
				break;
			}
		}

		return true;
	}

	Book::Book(string isbn, string author, string bookName, Date dateOfPublishing)
		: _author(author), _bookName(bookName), _dateOfPublishing(dateOfPublishing) {
		if (isbnIsCorrect(isbn)) { _isbn = isbn; }
		else {
			_isbn = "000-000-000-0";
			throw invalid_argument("Invalid ISBN: " + isbn);
		}
	}

	Book::Book()
	: _isbn("000-000-000-0"), _author(""), _bookName(""), _dateOfPublishing(Date())
	{	}

	void Book::setIsbn(const string & isbn) {
		if (isbnIsCorrect(isbn)) { _isbn = isbn; }
		else { throw invalid_argument("Invalid ISBN: " + isbn); }
	}

	ostream & operator<<(ostream & out, const Book & b) {
		return out
			<< "ISBN: " << b.isbn()
			<< ", " << b.author()
			<< ", " << b.bookName()
			<< ", " << b.dateOfPublishing();
	}

	bool operator==(const Book & self, const Book & other) {
		return self.isbn() == other.isbn();
	}

}