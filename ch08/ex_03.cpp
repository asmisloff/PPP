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
    if (x <= 0 || y <= x || n < 0) {
        error("Arguments error: x <= 0, y <= 0, y <= x or n < 0");
    }
    if (n > 0) v.push_back(x);
    else return; 
    if (n > 1) v.push_back(y);
    else return;
    for (int i=2; i<n; ++i) {
        v.push_back(v[i-1] + v[i-2]);
    }
}

int main() {
    vector<int> v;
    fibonacci(1, 2, v, 100);
    print(v);

    return 0;
}
