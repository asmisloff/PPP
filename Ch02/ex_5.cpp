#include "../std_lib_facilities.h"

int main()
{
    setlocale(0, "");
    cout << "Введите выражение: ";
    double a1, a2;
    char op;
    cin >> a1 >> a2 >> op;

    string s_op, s_eq;
    double res;
    switch (op) {
        case '+':
            s_op = "Сумма";
            s_eq = "равна";
            res = a1 + a2;
            break;
        case '-':
            s_op = "Разность";
            s_eq = "равна";
            res = a1 - a2;
            break;
        case '*':
            s_op = "Произведение";
            s_eq = "равно";
            res = a1 * a2;
            break;
        case '/':
            s_op = "Частное";
            s_eq = "равно";
            res = a1 / a2;
            break;
        default:
            cout << "Неизвестный оператор -- " << op;
            return -1;
    }

    cout << s_op << ' ' << a1 << " и " << a2 << ' ' << s_eq << ' ' << res << endl;
}