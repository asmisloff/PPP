#include "../std_lib_facilities.h"

int main()
{
	double grains = 1, prev;
	int i;
    for (i = 0; i < 1064; ++i)
    {
    	prev = grains;
    	cout << i+1 << ": " << (grains *= 2) << endl;
    	if (grains < prev || isinf(grains)) {
    		break;
    	}
    }

    cout << "Не более " << i << " клеток" << endl;
}