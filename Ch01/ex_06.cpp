#include "std_lib_facilities.h"
#include "helpers.h"

int main(int argc, char const *argv[])
{
	vector<int> numbers;
	for (int i = 0; i < 3; ++i)
		numbers.push_back(getint("Введите число: "));
	sort(numbers.begin(), numbers.end());
	for (auto n: numbers)
		cout << n << ", ";
	cout << '\b' << endl;

	return 0;
}