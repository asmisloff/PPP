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
    char ch = '0';
    while(cin) {
        ch = (char)cin.get();
        switch (ch) {
        case ' ':
            cout << "space" << endl;
            break;
        case '\n':
            cout << "\\n" << endl;
            break;
        default:
            cout << ch << endl;
        }
    }
}
