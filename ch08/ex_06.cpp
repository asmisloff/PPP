#include <vector>
#include <iostream>
#include <string>

using namespace std;

string vector_to_string(const vector<string>& v) {
    string s = "[";
    int n = v.size();
    for (int i=0; i<n-1; ++i) {
        s += v[i];
        s += ", ";
    }
    s += v[n-1] + "]";
    return s;
}

vector<string> reverse(const vector<string>& v) {
    vector<string> n;
    for (int i=v.size()-1; i>=0; --i) {
        n.push_back(v[i]);
    }
    return n;
}

void _reverse(vector<string>& v) {
    int n = v.size();
    string temp = "";
    for (int i=0; i < n/2; ++i) {
        temp = v[i];
        v[i] = v[n-i-1];
        v[n-i-1] = temp;
    }
}

int main() {
    vector<string> v = {"a", "b", "c", "d", "e", "5", "6", "7", "8", "9"};
    cout << "v = " << vector_to_string(v) << endl;
    cout << "reverse(v) = " << vector_to_string(reverse(v)) << endl;
    _reverse(v);
    cout << "After _reverse v = " << vector_to_string(v) << endl;

    return 0;
}
