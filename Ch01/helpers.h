double getdouble(const string& msg)
{
    cout << msg;
    string s;
    double i;
    cin >> s;
    try {
        i = stod(s);
    }
    catch (...) {
        cout << "Не корректный ввод. Повторить? (д/н): ";
        string res;
        cin >> res;
        if (res == "д" || res == "Д")
            getdouble(msg);
        else
            throw;
    }
    return i;
}

int getint(const string& msg)
{
    cout << msg;
    string s;
    int i;
    cin >> s;
    try {
        i = stoi(s);
    }
    catch (...) {
        cout << "Не корректный ввод. Повторить? (д/н): ";
        string res;
        cin >> res;
        if (res == "д" || res == "Д")
            getint(msg);
        else
            throw;
    }
    return i;
}
