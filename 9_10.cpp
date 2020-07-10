/*
Given n boxes of h, w and l. Build a stack with set of boxes where lower box is greater 
than the one above by a little
*/
#include<vector>
#include <algorithm>
#include <iostream>
#include<set>
using namespace std;

bool CompareBySize(const vector<int> v1, const vector<int> v2) {
	return v1[0] > v2[0];
}

class StackBoxes {

private:
	int max_h=0;
	int w = 0, h = 0, l = 0;
	void TallestHelper(vector<vector<int>>& dimentions, vector<vector<int>> stk, int curr_h) {

		if (curr_h > max_h) {
			max_h = curr_h;
		}

		for (int idx = 0; idx < dimentions.size(); idx++) {
			auto it = find(stk.begin(), stk.end(), dimentions[idx]);
			if (it == stk.end() and dimentions[idx][0] < stk.back()[0]  and dimentions[idx][1] < stk.back()[1] and 
				dimentions[idx][2] <  stk.back()[2]) {
				stk.push_back(dimentions[idx]);
				TallestHelper(dimentions, stk, curr_h+dimentions[idx][0]);
				stk.pop_back();
			}
		}
		return;
	}
	
	
	
	
public:
	
	int ConstructTallest(vector<vector<int>>& dimentions) {
		vector<vector<int>> recur_vec;
		sort(dimentions.begin(), dimentions.end(), CompareBySize);
		for (int index = 0; index < dimentions.size(); ++index) {
			recur_vec.push_back(dimentions[index]);
			TallestHelper(dimentions, recur_vec, dimentions[index][0]);
			recur_vec.pop_back();
		}
		return max_h;
	}
	
};

int main() {
	vector<vector<int>> input = {
		{9,9,9},
		{1,2,3},
		{3,4,5},
		{5,6,7}
	};
	StackBoxes stk1;
	int max_h = stk1.ConstructTallest(input);
}