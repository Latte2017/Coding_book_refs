/*
Given 2 sorted arrays A and B.
A is large enough to hold B
Copy all elements of B into A

1 2 3 11
4 5 6
*/
#include<vector>
#include <iostream>

using namespace std;

class Merge {

	int FindStart(vector<int>& v1, int val, int start) {

		if (val < v1[start]) {
			return -1;
		}
		else if (val > v1[v1.size() - 1]) {
			return v1.size();
		}

		int lo = start;
		int hi = v1.size() - 1;
		int mid;
		while (lo <= hi){
			mid = (hi - lo) / 2 + lo;

			if (val > v1[mid] and val < v1[mid+1]) {
				return mid;
			}

			else if (val > v1[mid]) {
				lo = mid + 1;
			}
			else {
				hi = mid-1;
			}
		}
		return lo;

	}
public:
	void MergeArray(vector<int>& v1, vector<int>& v2) {
		int begin_idx = 0;
		for (int idx = 0; idx < v2.size(); ++idx) {
			begin_idx = FindStart(v1, v2[idx], begin_idx);
			if (begin_idx == v1.size()) {
				for (int idx = 0; idx < v2.size(); ++idx) {
					v1.insert(v1.end() - 1 + idx, v2[idx]);
				}
				return;
			}
			else {
				v1.insert(v1.begin() + begin_idx+1, v2[idx]);
			}
			begin_idx++;
		}
		return;
	}
};

int main() {
	vector<int> v1 = { 1, 3, 5, 11 };
	vector<int> v2 = { 2, 4, 6 };
	Merge m1;
	m1.MergeArray(v1, v2);

	for (auto it = v1.begin(); it != v1.end(); ++it) {
		cout << *it << '\t';
	}
}
