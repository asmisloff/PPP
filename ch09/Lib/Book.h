#pragma once
#include <string>
#include <iostream>
#include "Date.h"

using namespace std;

namespace ExLib {
	class Book {
	public:
		Book(string isbn, string author, string bookName, Date dateOfPublishing);
		Book();

		const string& isbn() const { return _isbn; }
		const string& author() const { return _author; }
		const string& bookName() const { return _bookName; }
		const Date& dateOfPublishing() const { return _dateOfPublishing; }

		void setIsbn(const string& isbn);
		void setAuthor(const string& author) { _author = author; }
		void setBookName(const string& bookName) { _bookName = bookName; }
		void setDateOfPublishing(const Date& dateOfPublishing) { _dateOfPublishing = dateOfPublishing; }

		friend ostream& operator << (ostream& out, const Book& b);
		friend bool operator==(const Book& self, const Book& other);

	private:
		string _isbn;
		string _author;
		string _bookName;
		Date _dateOfPublishing;
	};
}
