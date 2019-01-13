#include "../std_lib_facilities.h"

string hundreds(int n)
{
    switch (n) {
    case 0:
        return "";
    case 1:
        return to_string(n) + " сотня";
    case 2: case 3: case 4:
        return to_string(n) + " сотни";
    case 5: case 6: case 7: case 8: case 9:
        return to_string(n) + " сотен";
    }
}

string decades(int n)
{
    switch (n) {
    case 0:
        return "";
    case 1:
        return to_string(n) + " десяток";
    case 2: case 3: case 4:
        return to_string(n) + " десятка";
    case 5: case 6: case 7: case 8: case 9:
        return to_string(n) + " десятков";
    }
}

string units(int n)
{
    switch (n) {
    case 0:
        return "";
    case 1:
        return to_string(n) + " единица";
    case 2: case 3: case 4:
        return to_string(n) + " единицы";
    case 5: case 6: case 7: case 8: case 9:
        return to_string(n) + " единиц";
    }
}

string to_str(int order, int digit)
{
    switch (order) {
    case 0:
        return units(digit);
    case 1:
        return decades(digit);
    case 2:
        return hundreds(digit);
    default:
        error("Десятичная разрядность больше 3 не поддерживается");
    }
}

int main()
{
    cout << "Число: ";
    vector<int> v;
    while (cin) {
        char c;
        cin >> c;
        if (!isdigit(c)) {
            break;
        }
        v.push_back(int(c - '0'));
    }
    
    int res = 0;
    int order = v.size() - 1;
    string string_repr = "";

    for(int i = 0; i < v.size(); i++) {
        res += pow(10, order) * v[i];
        string temp = to_str(order, v[i]);
        if (temp != "") {x
            string_repr += temp + ", ";
        }
        --order;
    }
    cout << "Введено число: " << res << "-- это " << string_repr << endl;

    return 0;
}
