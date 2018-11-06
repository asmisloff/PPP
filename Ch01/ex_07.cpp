#include "std_lib_facilities.h"
#include "helpers.h"

int main(int argc, char const *argv[])
{
	vector<string> strings;
	for (int i = 0; i < 3; ++i)
		strings.push_back(getstr("Введите строку: "));
	sort(strings.begin(), strings.end());
	for (auto s: strings)
		cout << s << ", ";
	cout << '\b' << endl;

	return 0;
}