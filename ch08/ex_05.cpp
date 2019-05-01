#include <vector>
#include <iostream>
#include <string>

using namespace std;

string vector_to_string(const vector<int>& v) {
    string s = "[";
    int n = v.size();
    for (int i=0; i<n-1; ++i) {
        s += to_string(v[i]);
        s += ", ";
    }
    s += to_string(v[n-1]) + "]";
    return s;
}

vector<int> reverse(const vector<int>& v) {
    vector<int> n;
    for (int i=v.size()-1; i>=0; --i) {
        n.push_back(v[i]);
    }
    return n;
}

void _reverse(vector<int>& v) {
    int n = v.size();
    int temp = 0;
    for (int i=0; i < n/2; ++i) {
        temp = v[i];
        v[i] = v[n-i-1];
        v[n-i-1] = temp;
    }
}

int main() {
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "v = " << vector_to_string(v) << endl;
    cout << "reverse(v) = " << vector_to_string(reverse(v)) << endl;
    _reverse(v);
    cout << "After _reverse v = " << vector_to_string(v) << endl;
    
    return 0;
}
