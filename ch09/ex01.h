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
	void read_ages(const vector<double> ages, const uint start_index = 0);
	void print() const;
	void sort();

private:
	vector<string> names;
	vector<double> ages;
};
