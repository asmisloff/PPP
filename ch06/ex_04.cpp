#include "../std_lib_facilities.h"

class Name_value
{
    public:
        Name_value(string n, int val)
            : name(n), value(val) {}
    
        string name = "";
        int value = 0;
};

int main()
{
    vector<Name_value> v;
    string name;
    int value;

    auto is_duplicate = [] (const string& name, const vector<Name_value>& v) {
        for (auto pair : v) {
            if (name == pair.name) {
                return true;
            }
        }
        return false;
    };

    while (cin) {
        cout << "Имя (Noname для завершения): ";
        cin >> name;
        if (name == "Noname") {
            break;
        }
        if (is_duplicate(name, v)) {
            cout << "Имя уже используется" << endl;
            continue;
        }
        cout << "Значение: ";
        cin >> value;
        v.push_back(Name_value(name, value));
    }

    
    for(auto pair : v) {
        cout << pair.name << " : " << pair.value << endl;
    }
    
}