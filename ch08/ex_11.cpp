#include <iostream>
#include <vector>

using namespace std;

template <typename T>
T maxv(const vector<T>& v) {
    T max_value = v[0];
    for (int i = 1; i < v.size(); ++i) {
        max_value = max_value >= v[i] ? max_value : v[i];
    }
    return max_value;
}

int main() {
    vector<int> i = {6, 2, 3, 4, 5};
    vector<double> d = {6.1, 2.2, 3.3, 4.4, 5.5};
    cout << maxv(i) << " " << maxv(d) << endl;

    return 0;
}