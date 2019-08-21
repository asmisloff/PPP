#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int get_age() {
    cout << "Введите возраст" << endl;
    int age = 0;
    while (true) {
        cin >> age;
        if (!cin.fail()) break;
        else {
            cout << "Нужно ввести целое число" << endl; 
            cin.clear();
        }
    }
    return age;
}

struct Pair {
public:
    string name;
    int age;
};

int main() {
    vector<string> names = {"Иван", "Сидор", "Карп", "Акулина", "Eвлампия"};
    vector<Pair> pairs;
    for (string name : names) {
        cout << "Имя: " << name << ". ";
        Pair pair;
        pair.name = name;
        pair.age = get_age();
        pairs.push_back(pair);
    }
    sort(pairs.begin(), pairs.end(), [](Pair x, Pair y) {return x.name < y.name;});
    for (Pair pair : pairs) {
        cout << pair.name << " : " << pair.age << endl;
    }
    
    return 0;
}
