//guess numbers

#include "../std_lib_facilities.h"

int main()
{
    cout << "Загадайте число от 1 до 100" << endl;
    int lower = 1;
    int upper = 100;
    char answer = 0;
    for (int i = 1; ; ++i) {
        int guess = (upper + lower) / 2;
        cout << "Попытка №" << i << ": " << guess << endl;
        for (;;) {
            cout << "Значение больше, меньше или равно загаданному? [</>/=]: ";
            cin >> answer;
            if (answer == '=') {
                cout << "Победа! Число попыток -- " << i << endl;
                return 0;
            }
            else if (answer == '<') {
                upper = guess;
                break;

            }
            else if (answer == '>') {
                lower = guess;
                break;
            }
            else {
                cout << "Некорректный символ. Повторить ввод? [y/n]: ";
                cin >> answer;
                if (answer == 'y') {
                    continue;
                }
                else {
                    return 0;
                }
            }
        }
    }
}
