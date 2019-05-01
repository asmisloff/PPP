#include "../std_lib_facilities.h"

void print(const vector<int>& v, string comment = "") {
    cout << "[ ";
    if (v.size() > 0) {
        for (int elt : v) {
            cout << elt << ", ";
        }
        cout << "\b\b";
    }
    cout << "]" << endl;
    cout << comment << endl;
}

void fibonacci(int x, int y, vector<int>& v, int n) {
    if (n > 0) v.push_back(min(x, y));
    else return; 
    if (n > 1) v.push_back(max(x, y));
    else return;
    for (int i=2; i<n; ++i) {
        v.push_back(v[i-1] + v[i-2]);
    }
}

int main() {
    vector<int> v;
    fibonacci(0, -1, v, 50);
    print(v);

    return 0;
}
