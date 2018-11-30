#include "../std_lib_facilities.h"

vector<char> variants = {'s', 'c', 'p'};

int compare(char x, char y)
{
    switch (x) {
        case 's':
            switch (y) {
                case 's':
                    return 0;
                case 'c':
                    return 1;
                default:
                    return -1;
            }
        case 'c':
            switch (y) {
                case 's':
                    return -1;
                case 'c':
                    return 0;
                default:
                    return 1;
            }
        case 'p':
            switch (y) {
                case 's':
                    return 1;
                case 'c':
                    return -1;
                default:
                    return 0;
            }
        default:
            return -2;
    }
}

char random_guess()
{
    return variants[clock() % 3];
}

void play()
{
    char user_guess;
    char comp_guess;
    while (true) {
        cout << "Цуефа! <s/c/p>: ";
        cin >> user_guess;
        comp_guess = random_guess();
        switch (compare(user_guess, comp_guess)) {
            case 0:
                cout << "Ничья" << endl << endl;
                break;
            case 1:
                cout << "Вы выиграли" << endl << endl;
                break;
            case -1:
                cout << "Вы проиграли" << endl << endl;
                break;
            default:
                cout << "Некорректный ввод" << endl;
                return;
        }
    }
}

int main()
{
    play();
    return 0;
}