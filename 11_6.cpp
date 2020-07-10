/*
Given an array which is sorted vertically and horizontally, find an element



1  2  3  4 
10 11 12 13
20 21 22 23
30 31 32 33

return indices of 22
*/

#include <vector>
#include<tuple>

using namespace std;

class Matrix {

	int BinarySearch(vector<int> row, int ele) {
		int lo = 0;
		int hi = row.size() - 1;

		while (lo <= hi) {

			int mid = lo + (hi - lo) / 2;

			if (ele == row[mid]) {
				return mid;
			}
			else if (ele > row[mid]) {
				lo = mid + 1;
			}
			else {
				hi = mid - 1;
			}
		}
		return -1;
	}
public:
	pair<int, int> Find(vector<vector<int>>& input_vec, int ele) {
		int len = input_vec[0].size();
		for (auto it = 0; it < input_vec.size(); ++it) {
			if (ele <= input_vec[it][len-1]) {
				int ret_val = BinarySearch(input_vec[it], ele);
				return make_pair(it, ret_val);
			}
		}
	}
};

int main() {
	vector<vector<int>> input_vec = {
										{1,  2,  3,  4},
										{10, 11, 12, 13},
										{20, 21, 22, 23},
										{30, 31, 32, 33}
									};
	Matrix m1;
	pair<int, int> index = m1.Find(input_vec, 19);
}