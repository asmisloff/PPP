#include "std_lib_facilities.h"

const double kms = 1.609;

double get_double(const string& msg)
{
	cout << msg;
	string s;
	cin >> s;
	double res;
	try {
		res = stod(s);
	}
	catch(...) {
		cout << "Неверный формат числа, повторить ввод? (д/н): ";
		cin >> s;
		if (s == "д" || s == "Д")
			get_double(msg);
		else
			throw;
	}
	return res;
}

int main()
{
	double miles;
	try {
		miles = get_double("Введите длину в милях: ");
	}
	catch(...) {
		cout << "Программа завершена.";
		return 0;
	}

	double res = miles * kms;
	cout << miles << " миль = " << res << " км." << endl;
	return res;
}