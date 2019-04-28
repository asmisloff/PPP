#include "../std_lib_facilities.h"

void print(vector<int>& v, string comment = "") {
    cout << "[ ";
    if (v.size() > 0) {
	    for (int elt : v) {
	        cout << elt << ", ";
	    }
	    cout << "\b\b";
	}
    cout << "]" << endl;
    cout << comment << endl;
}

int main() {
	vector<int> v = {1, 2, 3, 4, 5};
	print(v);

	return 0;
}