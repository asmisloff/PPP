#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
double median(vector<T>& v)
{
    vector<T> cp;
    copy(v.begin(), v.end(), back_inserter(cp));
    sort(cp.begin(), cp.end());
    int size = cp.size();
    if (size % 2) {
        cout << size % 2 << endl;
        return cp[size/2];
    }
    else {
        clog << cp[size/2 - 1] << "  " << cp[size/2] << endl;
        return (cp[size/2 - 1] + cp[size/2]) / 2.0;
    }
}

template <typename T>
struct Params 
{
    T min;
    T max;
    double mean;
    double median;
};

template <typename T>
Params<T> params(vector<T>& v)
{
    Params<T> p;

    T min_value = v[0];
    T max_value = v[0];
    T sum = v[0];
    for (int i=1; i < v.size(); ++i) {
        T curr = v[i];
        min_value = min_value <= curr ? min_value : curr;
        max_value = max_value >= curr ? max_value : curr;
        sum += curr;
    }
    p.min = min_value;
    p.max = max_value;
    p.mean = (double)sum / (double)v.size();
    p.median = median<T>(v);
    return p;
}

int main(int argc, char const *argv[])
{
    vector<int> v = {4, 5, 6, 7, 8, 0, 1, 2, 3, 9};
    auto p = params(v);
    cout << "Vector: ";
    for(auto item : v) {
        cout << item << ", ";
    }
    cout << endl;
    cout << "min: " << p.min << ", max: " << p.max
         << ", mean: " << p.mean << ", median: " << p.median << endl;
    return 0;
}
