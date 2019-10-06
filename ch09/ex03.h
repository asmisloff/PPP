#include <vector>
#include <string>

using namespace std;

class Name_pairs
{
public:
	Name_pairs();
	~Name_pairs();

	class Invalid { };
	
	void read_names(const vector<string> names);
	void read_ages(const vector<double> ages, const size_t start_index = 0);
	void sort();
	friend ostream& operator<<(ostream& os, const Name_pairs& np);

private:
	vector<string> names;
	vector<double> ages;
};
