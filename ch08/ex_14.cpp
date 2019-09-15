#include <string>
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct String_vector_info
{
    vector<int> sizes;
    string longest_string;
    string shortest_string;
    string lex_first;
    string lex_last;
};

String_vector_info string_log(const vector<string> &ss)
{
    String_vector_info si;
    int max = 0;
    int min = __INT_MAX__;
    int max_index = 0;
    int min_index = 0;
    int lex_first_index = 0;
    int lex_last_index = 0;
    for (int i=0; i < ss.size(); ++i)
    {
        int size = ss[i].size();
        
        if (size > max) {
            max = size;
            max_index = i;
        }
        if (size < min) {
            min = size;
            min_index = i;
        }

        if (ss[i] > ss[lex_last_index]) {
            lex_last_index = i;
        }
        if (ss[i] < ss[lex_first_index]) {
            lex_first_index = i;
        }
        
        si.sizes.push_back(size);
    }
    si.longest_string = ss[max_index];
    si.shortest_string = ss[min_index];
    si.lex_first = ss[lex_first_index];
    si.lex_last = ss[lex_last_index];
    return si;
}

int main()
{
    vector<string> ss;
    for (int i = 2; i < 1000; i += 100)
    {
        ss.push_back(to_string(i));
    }
    ss.push_back("abc");

    auto si = string_log(ss);

    for (int i = 0; i < si.sizes.size(); ++i)
    {
        cout << ss[i] << " --> " << si.sizes[i] << endl;
    }
    cout << "Longest string is " << si.longest_string << endl;
    cout << "Shortest string is " << si.shortest_string << endl;
    cout << "Lexicograpical first string is " << si.lex_first << endl;
    cout << "Lexicograpical last string is " << si.lex_last << endl;
    cout << ("a" < "b") << endl;
}
