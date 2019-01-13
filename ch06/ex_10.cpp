#include "../std_lib_facilities.h"

/*
  todo:
  -- Читать из cin строку и разбирать ее функцией strtoull
  -- Выход при вводе 'q'.
*/

class User_input
{
public:
    int a, b;
    string c;
    bool quit_program = false;
};

void clear_cin()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

User_input get_user_input()
{
    User_input inp;
    int a = 0;
    int b = 0;
    string c;

    for (;;) {
        cout << "Размер множества: ";
        if (!(cin >> a)) {
            cin.clear();
            string s;
            cin >> s;
            clear_cin();
            if (s == "q") {
                inp.quit_program = true; 
                return inp;
            }
            else {
                cout << "Необходимо ввести целое число" << endl;
                continue;
            }
        }
        else if (a <= 0) {
            cerr << "Размер множества должен быть положительным числом" << endl;
            continue;
        }
        break;
    }
    
    for (;;) {
        cout << "Размер подмножества: ";
        cin >> b;
        if (b > a || b <= 0) {
            cerr << "Размер подмножества не должен превышать размера множества" << endl;
            cout << "b = " << b << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            continue;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');	
        break;
    }

    for (;;) {
        cout << "Перестановка или сочетание? (п/с): ";
        cin >> c;
        if ((c != "п") && (c != "с")) {
            cerr << "Допустимые варианты ввода: \'п\' или \'с\'" << endl;
            continue;
        }
        break;
    }

    inp.a = a, inp.b = b, inp.c = c;
    return inp;
}

int factorial(unsigned long n)
{
    //cout << "Расчет " << n << "!" << endl;
    if (n == 0) {
        return 1;
    }
    unsigned long res = 1;
    unsigned long prev = res;
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

int compute_comb(int a, int b, string c)
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
        if (inp.quit_program) {
            cout << "Программа завершена" << endl;
            break;
        }
        
        try {
            res = compute_comb(inp.a, inp.b, inp.c);
        }
        catch (exception& e) {
            cerr << "------------- Ошибка -------------: " << endl;
            cerr << e.what() << endl;
            return 1;
        }
        cout << "--> " << res << endl;
    }

    return 0;
}


