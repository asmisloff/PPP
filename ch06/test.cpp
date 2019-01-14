#include "../std_lib_facilities.h"

int str_to_int(string s, string& err)
{
    int n = 0;
    for (char c : s) {
        if (isdigit(c)) {
            n = n*10 + (c - '0');
        }
        else {
            err = "Неверный формат числа. Нужно ввести челое положительное число.";
            return -1;
        }
    }
    return n;
}

int main()
{
    cout << ">> ";
    string s;
    cin >> s;
    string err = "";
    int n = str_to_int(s, err);
    if (err != "") {
        cerr << err << endl;
        return -1;
    }
    
    cout << ">> " << n << endl;
    
    return 0;
}
