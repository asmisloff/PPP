#include "../std_lib_facilities.h"

/*
  Тип "лексема"
  kind определяет вид лексемы: скобка, оператор, число или символ спец. формы.
  value: если лексема - число, хранит ее значение.
  name: имя спец. формы - let, quit, print или пользовательские.
*/
struct Token {
    char kind;
    double value;
    string name;
    Token(char ch) :kind(ch), value(0) { }
    Token(char ch, double val) :kind(ch), value(val) { }
    Token(char ch, string& name) :kind(ch), name(name) { }
};

/*
  Буферизированный поток лексем.
  Исходные данные берет из станлартного потока ввода.
*/
class Token_stream
{
    bool full;
    vector<Token> buffer;
public:
    Token_stream() :full(0) { }

    /*Read next token from stream*/
    Token get();
    Token look_in();
    void unget(Token t);

    void ignore(char);
};

//////////////////////////////////////////////////////////////////////
/////////////// Символы для обозначения особых форм //////////////////
//////////////////////////////////////////////////////////////////////
const char let = 'L';
const char quit = 'Q';
const char help = 'H';
const char print = ';';
const char constant = 'C';
const char number = '8';
const char name = 'a';
//////////////////////////////////////////////////////////////////////

/*Считывает лексему из входного потока и возвращает ее.*/
Token Token_stream::get()
{
    if (!buffer.empty()) {
        Token t = buffer.back();
        buffer.pop_back();
        if (buffer.empty()) {
            full = false;
        }
        return t;
    }
    char ch;
    while ((ch = (char)cin.get()) == ' ') {} //pass whitespaces
    switch (ch) {
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case ';':
    case '=':
        return Token(ch);
    case '.':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    {
	cin.unget();
        double val;
        cin >> val;
        return Token(number,val);
    }
    case '\n':
       return Token(print);
    default:
        if (isalpha(ch) || ch == '_') {
            string s;
            s += ch;
            while(cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_'))
                s+=ch;
            cin.unget();

            if (s == "let") {
                return Token(let);
            }
            else if (s == "const") {
                return Token(constant);
            }
            else if (s == "q") {
                return Token(quit);
            }
            else if (s == "h") {
                return Token(help);
            }
            else {
                return Token(name,s);
            }
        }
        else {
            error("Bad token");
        }
    }
}

void Token_stream::unget(Token t)
{
    full = true;
    buffer.push_back(t);
}

/*Пропустить все символы до c включительно*/
void Token_stream::ignore(char c)
{
    while (!buffer.empty()) {
        Token t = buffer.back();
        char kind = t.kind;
        buffer.pop_back();
        if (c == kind) {
            return;
        }
    }

    full = false;
    char ch;
    while (cin>>ch)
        if (ch==c) return;
}

/*
  Тип "пользовательская переменная". Хранит пару ключ-значение.
  Ключ - имя переменной, значение - число с плавающей точкой.
*/
struct Variable {
    string name;
    double value;
    bool mut;
    Variable(string n, double v, bool _mut) :name(n), value(v), mut(_mut) { }
};

class Symbol_Table
{
    vector<Variable> var_table;

public:
    //Получить значение переменной с именем s.
    double get_value(string s)
    {
        for (int i = 0; i<var_table.size(); ++i)
            if (var_table[i].name == s) return var_table[i].value;
        error("get: undefined name ",s);
    }

    //Присвоить переменной с именем s значение d
    void set_value(string s, double d)
    {
        for (int i = 0; i<=var_table.size(); ++i) {
            Variable v = var_table[i];
            if (v.name == s) {
                if (v.mut == false) {
                    error("Попытка присвоить значение константе");
                }
                var_table[i].value = d;
                return;
            }
        }
        error("set: undefined name ",s);
    }

    //Проверить, объявлена ли переменная.
    bool is_declared(string s)
    {
        for (int i = 0; i<var_table.size(); ++i)
            if (var_table[i].name == s) return true;
        return false;
    }

    void push_back(Variable v)
    {
        var_table.push_back(v);
    }

    int size() {
        return var_table.size();
    }
};

Symbol_Table names;
Token_stream ts;

void print_help() {
    cout << "------------- Help ------------" << endl;
}

double expression();

//Вычислить первичное выражение
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':
    {	double d = expression();
            t = ts.get();
            if (t.kind != ')') error("'(' expected");
    }
    case '-':
        return - primary();
    case number:
        return t.value;
    case name:
        return names.get_value(t.name);
    default:
        error("primary expected");
    }
}

//Вычислить терм
double term()
{
    double left = primary();
    while(true) {
        Token t = ts.get();
        switch(t.kind) {
        case '*':
            left *= primary();
            break;
        case '/':
        {	double d = primary();
                if (d == 0) error("divide by zero");
                left /= d;
                break;
        }
        default:
            ts.unget(t);
            return left;
        }
    }
}

//Вычислить выражение
double expression()
{
    double left = term();
    while(true) {
        Token t = ts.get();
        switch(t.kind) {
        case '+':
            left += term();
            break;
        case '-':
            left -= term();
            break;
        default:
            ts.unget(t);
            return left;
        }
    }
}

//Объявить переменную и вернуть ее значение.
double declaration(bool mut = true)
{
    Token t = ts.get();
    if (t.kind != 'a')
        error ("name expected in declaration");
    string name = t.name;
    if (names.is_declared(name))
        error(name, " declared twice");
    Token t2 = ts.get();
    if (t2.kind != '=')
        error("= missing in declaration of " ,name);
    double d = expression();
    names.push_back(Variable(name,d, mut));
    return d;
}

double assignment(const string& s)
{
    if (!names.is_declared(s))
        error("Undefined variable ", s);
    double value = expression();
    names.set_value(s, value);
    return value;
}

//Выполнить инструкцию и вернуть значение результирующего выражения.
double statement()
{
    Token t = ts.get();
    switch(t.kind) {
    case let:
        return declaration();
	case constant:
		return declaration(false);
    case name:
    {
        Token t2 = ts.get();
        if (t2.kind == '=') {
            return assignment(t.name);
        }
        else {
            ts.unget(t2);
        }
    }
    default:
        ts.unget(t);
        return expression();
    }
}
//Очистить входной поток. Выгрузить все данные до символа print включительно.
void clean_up_mess()
{
    ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

//Основной цикл вычислений
void calculate()
{
    while(true)
        try {
            cout << prompt;
            Token t = ts.get();
            while (t.kind == print) t=ts.get();
            //*cout << t.kind << endl;
            if (t.kind == quit) return;
            if (t.kind == help) {
                print_help();
                continue;
            }
            ts.unget(t);
            cout << result << statement() << endl;
	}
	catch(runtime_error& e) {
            cerr << e.what() << endl;
            clean_up_mess();
	}
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

int main()

    try {
        calculate();
        return 0;
    }
    catch (exception& e) {
        cerr << "exception: " << e.what() << endl;
        char c;
        while ((cin >> c) && (c!=';')) ;
        return 1;
    }
    catch (...) {
        cerr << "exception\n";
        char c;
        while (cin>>c && c!=';');
        return 2;
    }
