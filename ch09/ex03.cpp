#include <iostream>
#include <algorithm>
#include "ex03.h"
#include <utility>

using namespace std;

Name_pairs::Name_pairs() {}

Name_pairs::~Name_pairs() {}

void Name_pairs::read_names(const vector<string> names) {
    for (auto n: names) {
        this->names.push_back(n);
        this->ages.push_back(0.0);
    }
}

ostream& operator<<(ostream& os, const Name_pairs& np) {
    for (size_t i = 0; i < np.names.size(); ++i) {
        os << np.names[i] << " --- " << np.ages[i] << endl;
    }
    return os;
}

void Name_pairs::read_ages(const vector<double> ages, const size_t start_index) {
    for (size_t i = 0; i < min(ages.size(), this->names.size() - start_index); i++) {
        this->ages[start_index + i] = ages[i];
    }
}

void Name_pairs::sort() {
    for (size_t j = 1; j < names.size(); ++j) {
        for (size_t i = 0; i < names.size() - j; ++i) {
            if (names[i] > names[i+1]) {
                swap(names[i], names[i+1]);
                swap(ages[i], ages[i+1]);
            }
        }
    }
}

//-----------------------------------------------------------------
int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "Russian");
    Name_pairs np;
    vector<string> names = {"Вася", "Петя","Вова", "Маша", "Анна"};
    vector<double> ages = {20, 30, 40, 50, 13.5};
    np.read_names(names);
    np.read_ages(ages, 0);
    cout << np << endl;

    cout << endl
         << "Sorted pairs: " << endl
         << "-------------" << endl;
    
    np.sort();
    cout << np << endl;
    return 0;
}
