#include <iostream>
#include <vector>
#include <string>

using namespace std;

double index(vector<double>& weight, vector<double>& price) {
    if (weight.size() > price.size()) {
        throw "Error: Weight can't be longer then price";
        return -1;
    }
    double accumulator = 0.0;
    for (int i=0; i < weight.size(); ++i) {
        accumulator += weight[i] * price[i];
    }
    return accumulator;
}

int main() {
    vector<double> weight = {1, 2, 3, 4, 5, 6};
    vector<double> price = {1, 2, 3, 4, 5, 0.1, 7};
    try {
        cout << index(weight, price) << endl;
    }
    catch (const char* msg) {
        cerr << msg << endl;
    }
}