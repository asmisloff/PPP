#include "pch.h"
#include "Library.h"


//Library::Library() {
//}
namespace ExLib {
	void Library::addBook(Book b) {
		_books.push_back(b);
	}
	void Library::writeOffBook(Book b) {
		auto it = findBook(b);
		if (it != _books.end()) { _books.erase(it); }
		else { 
			throw BookIsMissingException("Book is missing -- " + b.bookName());
		}
	}
	void Library::giveOutBook(Book b, string name) {
		auto i_book = findBook(b);
		auto i_patron = patronByName(name);
		if (i_book == _books.end()) { throw BookIsMissingException("Book is missing -- " + b.bookName()); }
		if (i_patron == _readers.end()) { throw NotAPatronException("Not a patron -- " + name); }

		_books.erase(i_book);
		Transaction tr;
		tr.book = b;
		tr.opened = Date::today();
		tr.reader = *i_patron;
		_activeTransactions.push_back(tr);
	}
	void Library::takeBackBook(const Book & b, const Patron & p) {
		auto i_tr = findTransaction(b, p);
		_activeTransactions.erase(i_tr);
		_books.push_back(b);
	}
	void Library::addPatron(Patron p) {
		_readers.push_back(p);
	}
	vector<Transaction>::iterator Library::findTransaction(const Book& b, const Patron& p) {
		auto pred = [b, p](const Transaction& tr) {return (tr.book == b && tr.reader == p); };
		auto i_tr = find_if(_activeTransactions.begin(), _activeTransactions.end(), pred);
		if (i_tr == _activeTransactions.end()) { throw TransactionNotFoundException("Transaction not found -- Patron: " + p.name() + ", book: " + b.bookName()); }
		return i_tr;
	}
	ostream & operator<<(ostream & out, const Transaction & tr) {
		return out
			<< "Book: " << tr.book << endl
			<< "Patron: " << tr.reader.name() << endl;
	}
	NotAPatronException::NotAPatronException(string msg) : LibraryException(msg)
	{ }
	/*string NotAPatronException::what() const {
		return msg;
	}*/
	LibraryException::LibraryException(string msg) {
		this->msg = msg; 
	}
	string LibraryException::what() const { 
		return msg;
	}
}
