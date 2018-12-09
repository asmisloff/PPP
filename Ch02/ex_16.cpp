#include "../std_lib_facilities.h"

int main()
{
    vector<int> v;
    int n;
    while (cin) {
        cout << "Введите число: ";
        cin >> n;
        v.push_back(n);
    }
    
    int cnt = 0;
    int mode = 0;
    for (int i = 0; i < v.size(); ++i) {
        int k = 0;
        n = v[i];
        for (int j = i; j < v.size(); ++j) {
            if (n == v[j]) {
                ++k;
            }
        }
        if (k > cnt) {
            cnt = k;
            mode = n;
        }
    }
    
    cout << "Мода введенной последовательности: " << mode << endl;
}