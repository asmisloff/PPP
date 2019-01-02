#include "../std_lib_facilities.h"

vector<string> articles = {"the", "a", "an"};
vector<string> unions = {"and", "or", "but"};
vector<string> nouns = {"birds", "fish", "c++"};
vector<string> verbs = {"rules", "swim", "fly"};

class Buffer
{
    public:

        Buffer() : s(""), full(false) {}
        
        void push(string s)
        {
            if (!full) {
                this->s = s; 
                full = true;
            }
            else {
                error("push в полный буфер");
            }
        }

        string get()
        {
            full = false;
            return s;
        }

        bool is_full()
        {
            return full;
        }
    
    private:
        string s;
        bool full;
};

Buffer buf;

bool contains(vector<string> v, string s)
{
    for (int i = 0; i < v.size(); ++i) {
        if (s == v[i]) {
            return true;
        }
    }
    return false;
}

string get()
{
    if (buf.is_full()) {
        return buf.get();
    }
    else {
        string s;
        cin >> s;
        return s;
    }
}

void read_article()
{
    string s = get();
    if (contains(articles, s)) {
        //cout << "Считан артикль " << s << endl;
    }
    else {
        buf.push(s);
        //cout << s << " не артикль, помещено в буфер" << endl;
    }
}

void read_noun()
{
    string s = get();
    if (contains(nouns, s)) {
        //cout << "Считано существительное " << s << endl;
    }
    else {
        error(s, " не существительное");
    }
}

void read_verb()
{
    string s = get();
    if (contains(verbs, s)) {
        //cout << "Считан глагол " << s << endl;
    }
    else {
        error(s, " не глагол");
    }
}

bool read_union()
{
    string s = get();
    if (contains(unions, s)) {
        //cout << "Союз " << s << endl;
        return true;
    }
    else {
        buf.push(s);
        return false;
    }
}

void read_dot()
{
    string s = get();
    if (s != ".") {
        error("Предложение не завершается точкой");
    }
}

void read_sentence() {
    read_article();
    read_noun();
    read_verb();
    if (read_union()) {
        read_sentence();
    }
    else {
        read_dot();
    }
}

int main(int argc, char const *argv[])
{
    try {
        read_sentence();
    }
    catch (exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
        return -1;
    }

    cout << "Предложение корректно" << endl;
    return 0;
}
