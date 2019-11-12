#include "pch.h"
#include <iostream>
#include "Patron.h"
#include "Date.h"
#include "Book.h"
#include "Library.h"

using namespace std;
using namespace ExLib;

void testPatron() {
	Patron p(1, "MrX", 100);
	cout << p.id() << ": " << p.name() << endl;
}

void testDate() {
	Date d(2000, Jan, 30);
	cout << d << endl;
	try {
		Date d1(2000, Jan, 32);
	}
	catch (InvalidDate) {
		cout << "Invalid date: " << endl;
	}
}

void testBook() {
	try {
		Book b("111-111-222-q", "Leo Tolstoy", "War and Peace", Date(1869, July, 13));
		cout << b << endl;
		Book b1("111-111-22q-q", "Leo Tolstoy", "Anna Karenina", Date(1869, July, 13));
		cout << b1 << endl;
	}
	catch (invalid_argument err) {
		cout << err.what() << endl;
	}
}

void testTransaction() {
	Transaction tr;
	tr.book = Book("111-111-222-q", "Leo Tolstoy", "War and Peace", Date(1869, July, 13));
	cout << tr.book;
}

void testLibrary() {
	Library lib;
	Book b1("111-111-222-q", "Leo Tolstoy", "War and Peace", Date(1869, July, 13));
	Book b2("111-111-223-q", "Leo Tolstoy", "Anna Karenina", Date(1869, July, 13));
	lib.addBook(b1);
	lib.addBook(b2);
	Patron p(1, "MrX", 100);
	lib.addPatron(p);

	try {
		lib.giveOutBook(b1, "MrY");
		cout << *lib.findTransaction(b1, p);
	}
	catch (LibraryException& e) {
		cout << "Error: " << e.what();
	}
}

int main() {
	/*testPatron();
	testDate();
	testBook();
	testTransaction();*/
	testLibrary();
}
