#include "../std_lib_facilities.h"

class User_input
{
public:
    int a, b;
    string c;
};

void clear_cin()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int str_to_int(string s)
{
    int n = 0;
    for (char c : s) {
        if (isdigit(c)) {
            n = n*10 + (c - '0');
        }
        else {
            return -1;
        }
    }
    return n;
}

User_input get_user_input()
{
    User_input inp;
    
    for (;;) {
        cout << "Размер множества: ";
        string s;
        cin >> s;
        if (s == "q") {
            exit(0);
        }
        int a = str_to_int(s);
        if (a == -1) {
            cout << "Неверный формат числа" << endl;
            continue;
        }
        else {
            inp.a = a;
            cerr << a << endl;
            break;
        }
    }
    
    for (;;) {
        cout << "Размер подмножества: ";
        string s;
        cin >> s;
        int b = str_to_int(s);
        if (s == "q") {
            exit(0);
        }
        if (b == -1) {
            cout << "Неверный формат числа" << endl;
            continue;
        }
        else {
            if (b > inp.a) {
                cerr << "Размер подмножества не должен превышать размера множества" << endl;
                continue;
            }
            inp.b = b;
            break;
        }
    }

    for (;;) {
        cout << "Перестановка или сочетание? (п/с): ";
        string c;
        cin >> c;
        if (c == "q") {
        	exit(0);
        }
        else if ((c == "п") || (c == "с")) {
        	inp.c = c;
        	break;
        }
        else {
            cerr << "Допустимые варианты ввода: \'п\' или \'с\'" << endl;
            continue;
        }
    }

    cout << "a = " << inp.a << ", b = " << inp.b << ", c = " << inp.c << endl;
    return inp;
}

unsigned long long factorial(unsigned int n)
{
    //cout << "Расчет " << n << "!" << endl;
    if (n == 0) {
        return 1;
    }
    unsigned long long res = 1;
    unsigned long long prev = res;
    for ( ; n > 1; --n) {
        prev = res;
        res *= n;
        //cout << "prev = " << prev << ", res = " << res << endl;
        if (res < prev) {
            error("factorial -- Ошибка переполнения");
        }
    }
    return res;
}

unsigned long long compute_comb(int a, int b, string c)
{
    if (c == "п") {
        return factorial(a) / factorial(a - b);
    }
    else {
        return factorial(a) / (factorial(a - b) * factorial(b));
    }
}

int main()
{
    User_input inp;
    int res;
    
    while (true) {
        inp =  get_user_input();        
        try {
            res = compute_comb(inp.a, inp.b, inp.c);
        }
        catch (exception& e) {
            cerr << "------------- Ошибка -------------: " << endl;
            cerr << e.what() << endl;
            continue;
        }
        cout << "--> " << res << endl;
    }

    return 0;
}