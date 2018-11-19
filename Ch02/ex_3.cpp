#include "../std_lib_facilities.h"

double min(vector<double>& v)
{
	auto it = min_element(v.begin(), v.end());
	int index = distance(v.begin(), it);
	return v[index];
}

double max(vector<double>& v)
{
	vector<double>::iterator it = max_element(v.begin(), v.end());
	int index = distance(v.begin(), it);
	return v[index];
}

int main()
{
	double d;
	vector<double> v;
	auto prompt = [] {
		cout << "Введите число: ";
	};
	prompt();
	while (cin >> d) {
		v.push_back(d);
		prompt();
	}

	if (v.size() > 0) {
		double sum = accumulate(v.begin(), v.end(), 0);
		cout << "Сумма = " << sum << endl;
		cout << "Минимальное значение = " << min(v) << endl;
		cout << "Максимальное значение = " << max(v) << endl;
		cout << "Среднее значение = " << sum / v.size() << endl;
	}

	return 0;
}
