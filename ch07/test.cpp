#include "../std_lib_facilities.h"

bool is_variable(string s)
{
    return true;
}

string assignment()
{
    char ch;
    string identifier = "";
    while (cin.get(ch)) {
        cout << ":: ch = " << ch << endl;
        if (isspace(ch)) {
            cout << "space ";
            continue;
        }
        else if(isalpha(ch) || isdigit(ch) || ch == '_') {
            cout << "identifier ";
            identifier += ch;
        }
        else if (ch == '=') {
            cout << "equation. Identifier = " << identifier << endl;
            return identifier;
        }
        else {
            cin.putback(ch);
            for (int i = identifier.size() - 1; i >= 0; --i) {
                cin.putback(identifier[i]);
            }
            return "";
        }
    }
}

int main()
{
    // string var_name = assignment();
    // if (var_name != "") {
    //     cout << "assignment to " << var_name << endl;
    // }
    // else {
    //     string s;
    //     getline(cin, s);
    //     cout << "Not assignment. In cin: " << s << endl;
    // }
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    while (!v.empty()) {
        cout << v.back() << ' ';
        v.pop_back();
    }
    cout << endl;
}
