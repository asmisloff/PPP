#include "../std_lib_facilities.h"

double med(vector<int>& v)
{
	sort(v.begin(), v.end());
	int sz = v.size();
	if (sz % 2 == 0) {
		return (v[sz / 2] + v[sz / 2 - 1]) / 2.0;
	}
	else {
		return v[sz / 2];
	}
}

int main()
{
	vector<int> v;

	for (int i=0; i<99; ++i) {
		v.push_back(i);
	}

	cout << med(v) << endl;

	return 0;
}