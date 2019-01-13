#include "../std_lib_facilities.h"

int main()
{
    cout << ">> ";
    int a;
    if (cin >> a) {;
        cout << ">> " << a << " -> int" << endl;
    }
    else {
        cout << "-----Ошибка чтения числа -----" << endl;
        cout << ">> a = " << a << endl;
        cin.clear();
    }
    string s;
    cin >> s;
    cout << ">> " << s << " -> string" << endl;
    
    return 0;
}

// (progn
//  (interactive)
//  (compile "g++ -std=c++11 test.cpp -o test"))

