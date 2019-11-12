#pragma once

#include <vector>
#include "Book.h"
#include "Date.h"
#include "Patron.h"
#include <algorithm>

namespace ExLib {

	struct Transaction {
		Book book;
		Patron reader;
		Date opened;
		Date closed;
	};

	ostream& operator<<(ostream& out, const Transaction& tr);

	class LibraryException {
	public:
		LibraryException(string msg);
		virtual string what() const;
	protected:
		string msg;
	};
	class BookIsMissingException : public LibraryException {
	public:
		BookIsMissingException(string msg) : LibraryException(msg) {
		}
		string what() const { return msg; }
	};
	class NotAPatronException : public LibraryException {
	public:
		NotAPatronException(string msg);
		//string what() const;
	};
	class TransactionNotFoundException : public LibraryException {
	public:
		TransactionNotFoundException(string msg) : LibraryException(msg) {
		}
	};

	class Library {
	public:
		//Library();
		void addBook(Book b);
		void writeOffBook(Book b);
		void giveOutBook(Book b, string name);
		void takeBackBook(const Book& b, const Patron& p);
		void addPatron(Patron p);

		vector<Transaction>::iterator findTransaction(const Book&, const Patron&);
	private:
		vector<Book> _books;
		vector<Patron> _readers;
		vector<Transaction> _activeTransactions;

		vector<Book>::iterator findBook(const Book& b) { return find(_books.begin(), _books.end(), b); }
		vector<Patron>::iterator patronByName(const string& name) {
			return find_if(
				_readers.begin(),
				_readers.end(),
				[name](Patron p) {return p.name() == name; });
		}
	};
}