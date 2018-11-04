#include "../std_lib_facilities.h"

int getint(const string& msg)
{
    cout << msg;
    string s;
    int i;
    cin >> s;
    try {
        i = stoi(s);
    }
    catch (...) {
        cout << "Не корректный ввод. Повторить? (д/н): ";
        string res;
        cin >> res;
        if (res == "д" || res == "Д")
            getint(msg);
        else
            throw;
    }
    return i;
}

int main(int argc, char const *argv[])
{
    int val1, val2;
    try {
        val1 = getint("Введите первое число: ");
        val2 = getint("Введите второе число: ");

        cout << "Наибольшее значение: " << max(val1, val2) << endl;
        cout << "Наименьшее значение: " << min(val1, val2) << endl;
        cout << val2 << " - " << val1 << " = " << val2 - val1 << endl;
        cout << val2 << " + " << val1 << " = " << val2 + val1 << endl;
        cout << val2 << " * " << val1 << " = " << val2 * val1 << endl;
        cout << val2 << " / " << val1 << " = " << double(val2) / double(val1) << endl;
    }
    catch(...) {
        cout << "Программа завершена." << endl;
    }

    return 0;
}