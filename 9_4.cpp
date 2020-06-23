/*
Return subsets of all sets
*/

#include<vector>
#include<set>
#include <iostream>

using namespace std;

class Subsets {
private:
	vector<set<int>> output;
	void Convert(set<int> input, int len) {
		int index = 0;
		set<int> tmp_set;
		auto it = input.begin();
		for (int k = len; k > 0; k >>= 1) {
			if ((k & 1) == 1) {
				tmp_set.insert(*it);
			}
			it++;
		}
		output.push_back(tmp_set);
	}
public:
	vector<set<int>> generateSubSets(set<int> input) {
		int max = 1 << input.size(); //2^n combinations
		for (int iter = 0; iter < max; iter++) {
			Convert(input, iter);
		}
		return output;
	}
};

int main() {
	set<int> input = { 1,2,3,4,5 };
	Subsets s1;
	vector<set<int>> output = s1.generateSubSets(input);
	for (auto it = output.begin(); it != output.end(); ++it) {
		for (auto it2 = (*it).begin(); it2 != (*it).end(); ++it2) {
			cout << *it2 << "\t";
		}
		cout << endl;
	}
}