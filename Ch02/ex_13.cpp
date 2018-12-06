#include "../std_lib_facilities.h"
/*
#include <iostream>
#include <vector>

using namespace std;*/

vector<int> primes(int n)
{
    vector<int> v(n);
    vector<int> res;
    for (int i=2; i<n; i++) {
        if (v[i] == 0) {
            res.push_back(i);
            for (int j=i*i; j<n; j+=i) {
                v[j] = 1;
            }
        }
    }
    return res;
}

int main()
{
    auto v = primes(100);
    for (auto i : v) {
        cout << i << ", ";
    }
    cout << "\b\b  " << endl;
}