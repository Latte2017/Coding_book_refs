/*
Return subsets of all sets
*/

#include<vector>
#include<set>
#include <iostream>
#include <algorithm>

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
	
	void recurHelper(set<int>& input, int n, set<int>& recur, set<int>::iterator it) {

		if (n==0) {
			output.push_back(recur);
			if (!recur.empty()) {
				recur.erase(*recur.rbegin());
			}
			return;
		}

		for (int i = 0; i < input.size(); ++i) {
			if (it != input.end()) {
				recur.insert(*it);
				advance(it, 1);
				recurHelper(input, n-1, recur, it);
			}
			else {
				if (!recur.empty()) {
					recur.erase(*recur.rbegin());
				}
				return;
			}
		}
	}
	

public:

	//Use Recursive method
	vector<set<int >> generateSubSets2(set<int>& input) {
		output.clear();
		set<int> recur = {};
		for (int i = 0; i < input.size()+1; ++i) {
			recurHelper(input, i, recur, input.begin());
			recur.clear();
		}
		return output;
	}

	//Generate using bit method
	vector<set<int>> generateSubSets(set<int> input) {
		int max = 1 << input.size(); //2^n combinations
		for (int iter = 0; iter < max; iter++) {
			Convert(input, iter);
		}
		return output;
	}
};

int main() {
	set<int> input = { 1,2,3,4, 5 };
	Subsets s1;
	vector<set<int>> output = s1.generateSubSets(input);
	vector<set<int>> output1 = s1.generateSubSets2(input);
	sort(output.begin(), output.end());
	sort(output1.begin(), output1.end());
	
	if (output != output1) {
		cout << "Results donot match" << endl;
	}
	else {
		cout << "Results match" << endl;
	}

	/*
	cout << "size of output " << output.size() << endl;
	for (auto it = output.begin(); it != output.end(); ++it) {
		for (auto it2 = (*it).begin(); it2 != (*it).end(); ++it2) {
			cout << *it2 << "\t";
		}
		cout << endl;
	}

	
	cout << "size of output2 " << output1.size() << endl;
	for (auto it = output1.begin(); it != output1.end(); ++it) {
		for (auto it2 = (*it).begin(); it2 != (*it).end(); ++it2) {
			cout << *it2 << "\t";
		}
		cout << endl;
	}
	*/

}