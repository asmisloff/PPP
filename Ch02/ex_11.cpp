#include "../std_lib_facilities.h"

void primes(int n, vector<int>& v)
{
    for (int i=2; i<n; i++) {
        for (int j=2; j<i; j++) {
            if (i % 2 == 0) {
                break;
            }
            else if (i % j == 0) {
                break;
            }
            if (j == i - 1) {
                v.push_back(i);
            }
        }
    }
}

int main()
{
    const int N = 1000;
    cout << "Простые числа от 2 до " << N << endl;
    vector<int> v;
    primes(N, v);
    for (int i : v){
        cout << i << ", ";
    }
    cout << "\b\b  " << endl;
}