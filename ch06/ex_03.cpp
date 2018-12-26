#include "../std_lib_facilities.h"

double expression();
double term();
double primary();

double factorial(double n) {
	int i = int(n);
	int f = 1;
	if (n < 0) {
		error("Факториал вычисляется только для положительных чисел -- ");
	}
	if (n == 0) {
		return 1;
	}
	if (n - i < 0.0001) {
		for ( ; i > 0; i--) {
			f *= i;
		}
	}
	else if (n - i > 0.9999) {
		i++;
		for (; i > 0; i--) {
			f *= i;
		}
	}
	else {
		error("Факториал вычисляется только для целых чисел");
	}
	return f;
}

class Token
{
public:
	char kind;
	double value;
	Token(char ch)
		: kind(ch), value(0) {}
	Token(char ch, double val)
		: kind(ch), value(val) {}
};

class Token_stream
{
public:
	Token_stream();
	Token get();
	void putback(Token t);

private:
	bool full;
	Token buffer;
};

Token_stream::Token_stream()
	: full(false), buffer(0) {}

void Token_stream::putback(Token t)
{
	if (full) {
		error("putback() в полный буфер");
	}
	buffer = t;
	full = true;
}

Token Token_stream::get()
{
	if (full) {
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;

	switch	(ch) {
		case ';': case 'q': case '(': case ')': case '+': case '-': case '*': case '/':
        case '{': case '}': case '!':
			return Token(ch);
		case '.':
		case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7':
		case '8': case '9':
		{
			cin.putback(ch);
			double val;
			cin >> val;
			return Token(8, val);
		}
		default:
			error("Неправильная лексема -- " + ch);
	}
}

Token_stream ts;

double expression()
{
	double left = term();
	Token t = ts.get();

	while (true) {
		switch (t.kind) {
			case '+':
				left += term();
				t = ts.get();
				break;
			case '-':
				left -= term();
				t = ts.get();
				break;
			default:
				ts.putback(t);
				return left;
		}
	}
}

double term()
{
	double left = primary();
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
			case '*':
				left *= primary();
				t = ts.get();
				break;
			case '/':
			{
				double d = primary();
				if (d == 0) {
					error("Деление на ноль");
				}
				left /= d;
				t = ts.get();
				break;
			}
			default:
				ts.putback(t);
				return left;
		}
	}
}

double primary()
{
	Token t = ts.get();
	double res = 0.0;
	switch (t.kind) {
		case '-':
			res = -1 * primary();
			break;
		case 8:
			res = t.value;
			cout << "Считано число " << res << endl;
			break;
		case '(':
			res = expression();
			t = ts.get();
			if (t.kind != ')') {
				error("Ожидалась закрывающая скобка");
			}
			break;
		case '{':
			res = expression();
			t = ts.get();
			if (t.kind != '}') {
				error("Ожидалась закрывающая фигурная скобка");
			}
			break;
		default:
			error("Ожидалось первичное выражение");
			break;
	}

		cout << "res = " << res << endl;
		t = ts.get();
		if (t.kind == '!') {
			return factorial(res);
		}
		ts.putback(t);
		return res;
}

int main()
{
	double val = 0;
	try {
		while (cin) {
			Token t = ts.get();
			if (t.kind == 'q') {
				break;
			}
			if (t.kind == ';') {
				cout << "=" << val << endl;
			}
			else {
				ts.putback(t);
				val = expression();
			}
		}
	}
	catch (exception& e) {
		cerr << e.what();
		return -1;
	}
	catch (...) {
		cerr << "Неизвестная ошибка";
		return -2;
	}

	return 0;
}