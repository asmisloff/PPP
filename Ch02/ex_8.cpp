#include "../std_lib_facilities.h"

int main()
{
	long long grains = 1;
    for (int i = 0; i < 64; ++i)
    {
    	cout << i+1 << ": " << (grains *= 2) << endl;
    }

    cout << grains << " of grains" << endl;
}