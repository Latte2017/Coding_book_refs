/*

Given an array find the continuous sub sequence max sum

2, -8, 3, -2, 4 10

Kadane's Algo
*/

#include<vector>
#include <algorithm>

using namespace std;

int MaxSum(vector<int> input_arr) {
	int max_so_far = 0, max_sub_array = 0;

	for (auto it : input_arr) {
		max_so_far = max(max_so_far + it, it);
		if (max_sub_array < max_so_far) {
			max_sub_array = max_so_far;
		}
	}
	return max_sub_array;
}


int main() {
	vector<int> input_vec = { -2, -8, 3, -2, 4, -10 };
	int max_sum = MaxSum(input_vec);
}