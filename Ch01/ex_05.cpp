#include "../std_lib_facilities.h"

double getdouble(const string& msg)
{
    cout << msg;
    string s;
    double i;
    cin >> s;
    try {
        i = stod(s);
    }
    catch (...) {
        cout << "Не корректный ввод. Повторить? (д/н): ";
        string res;
        cin >> res;
        if (res == "д" || res == "Д")
            getdouble(msg);
        else
            throw;
    }
    return i;
}

int main(int argc, char const *argv[])
{
    double val1, val2;
    try {
        val1 = getdouble("Введите первое число: ");
        val2 = getdouble("Введите второе число: ");

        cout << "Наибольшее значение: " << max(val1, val2) << endl;
        cout << "Наименьшее значение: " << min(val1, val2) << endl;
        cout << val2 << " - " << val1 << " = " << val2 - val1 << endl;
        cout << val2 << " + " << val1 << " = " << val2 + val1 << endl;
        cout << val2 << " * " << val1 << " = " << val2 * val1 << endl;
        cout << val2 << " / " << val1 << " = " << val2 / val1 << endl;
    }
    catch(...) {
        cout << "Программа завершена." << endl;
    }

    return 0;
}