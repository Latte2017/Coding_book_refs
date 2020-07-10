/*
Given an array which is rotated at some pivot. Find an element

4 5 1 2 3

find 5

Binary Search
*/

#include<vector>

using namespace std;

class Binary {
public:

	int FindSmallestIndex(vector<int>& input, int lo, int hi) {
		//If not rotated
		if (input[lo] < input[hi]) {
			return 0;
		}

		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;

			if (input[mid] > input[mid + 1]) { // 4 10 2
				return mid + 1;
			}

		}
	}

	int findNum(vector<int> input, int num) {
		

	}
};


int main() {
	vector<int> input_vec = { 4,5,6,7,0,1,2};
	int find = 0;
	Binary b1;
	int index = b1.findNum(input_vec, find);

}
