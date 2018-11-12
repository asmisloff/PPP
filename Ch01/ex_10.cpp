#include "std_lib_facilities.h"
#include "helpers.h"

double calculate(string, string, string, string&);

int main(int argc, char const *argv[])
{
	cout << "Введите выражение: ";
	string _operator, op_1, op_2;
	string error_msg = "";
	cin >> _operator;
	cin >> op_1 >> op_2;
	double res = calculate(_operator, op_1, op_2, error_msg);
	if (error_msg == "") {
		cout << "= " << res << endl;
	}
	else
		cout << error_msg << endl;

	return 0;
}

double calculate(string _operator, string op_1, string op_2, string& error_msg)
{
	double d_op_1, d_op_2, res;
	try {
		d_op_1 = stod(op_1);
	}
	catch (...) {
		error_msg = "Ошибка! Первый операнд (" + op_1 + ") не число.";
		return 0;
	}
	try {
		d_op_2 = stod(op_2);
	}
	catch (...) {
		error_msg = "Ошибка! Второй операнд (" + op_2 + ") не число.";
		return 0;
	}
	if (_operator == "+")
		res = d_op_1 + d_op_2;
	else if (_operator == "-")
		res = d_op_1 - d_op_2;
	else if (_operator == "*")
		res = d_op_1 * d_op_2;
	else if (_operator == "/")
		res = d_op_1 / d_op_2;
	else {
		error_msg = "Ошибка! Неизвестный оператор [" + _operator + "].";
		return 0;
	}
	return res;
