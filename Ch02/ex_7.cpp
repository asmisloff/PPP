#include "../std_lib_facilities.h"

vector<string> numbers = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

double to_double(string s, const vector<string>& v = numbers)
{
    try
    {
        return stoi(s);
    }
    catch (...)
    {
        for (int i=0; i < v.size(); ++i)
        {
            if (v[i] == s)
            {
                return i;
            }
        }
        throw;
    }
}

int main()
{
    cout << "Введите выражение: ";
    string sa1, sa2;
    double a1, a2;
    char op;
    cin >> sa1 >> sa2 >> op;
    try
    {
        a1 = to_double(sa1);
        a2 = to_double(sa2);
    }
    catch (...)
    {
        error("Неизвестное число");
        return -1;
    }

    string s_op, s_eq;
    double res;
    switch (op)
    {
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
