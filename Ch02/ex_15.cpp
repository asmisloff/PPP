#include "../std_lib_facilities.h"

void naive_algorithm(int n, vector<int>& primes)
{
    auto vector_contains_dividors = [](const vector<int>& v, int i) {
        for (int n : v) {
            if (i % n == 0) {
                return true;
            }
            if ((double)i / n <= 2) {
                return false;
            }
        }
        return false;
    };
    
    primes.push_back(2);
    for (int i = 3; n > 0; i+=2) {
        if (!vector_contains_dividors(primes, i)) {
            primes.push_back(i);
            --n;
        }
    }
}

void fill_sieve(vector<int>& sieve, int begin)
{
    for (int i = 0; i < sieve.size(); ++i) {
        sieve[i] = begin++;
    }
}

void sift_number(int n, vector<int>& sieve, int sieve_0)
{
    int i = 0;
    if (sieve_0 % n != 0) {
        i += n - sieve_0 % n;
    }
    while (i < sieve.size()) {
        sieve[i] = 0;
        i += n;
    }
}

void sift_numbers(vector<int>& numbers, vector<int>& sieve, int sieve_0)
{
    for (int n : numbers) {
        sift_number(n, sieve, sieve_0);
    }
}

void collect(vector<int>& sieve, vector<int>& primes)
{
    for (int n : sieve) {
        if (n != 0) {
            primes.push_back(n);
        }
    }
}

void sift(vector<int>& sieve)
{
    for (int i = 0; i < sieve.size(); ++i) {
        int curr = sieve[i];
        if (curr != 0) {
            for (int j = i + curr; j < sieve.size(); j += curr) {
                sieve[j] = 0;
            }
        }
    }
}

void print_vector(const vector<int>& v)
{
    for (int elt : v) {
        cout << elt << ", ";
    }
    cout << "\b\b  " << endl;
}

void erathosphen(int n, vector<int>& primes)
{
    int pass = 0;
    const int CAPACITY = n;
    vector<int> sieve(CAPACITY);
    fill_sieve(sieve, 2);
    while (primes.size() < n) {
//         cout << "pass " << pass << ", sieve_0 = " << sieve[0] << endl;
        sift_numbers(primes, sieve, sieve[0]);
        sift(sieve);
        collect(sieve, primes);
        pass++;
        fill_sieve(sieve, CAPACITY * pass + 2);
//         cout << "primes: ";
//         print_vector(primes);
    }
}

int main(int argc, char** argv)
{
    int n = atoi(argv[1]);
    vector<int> primes;
//     naive_algorithm(n, primes);
    erathosphen(n, primes);
//     vector<int> v(10);
//     fill_sieve(v, 12);
//     sift_number(3, v, v[0]);
    print_vector(primes);    
    
    return 0;
}