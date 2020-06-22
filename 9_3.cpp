/*
A magic index is A[i] = i
Given a sorted array return a magic index
*/

#include<iostream>
#include<array>
using namespace std;

class MagicNumber {
public:
	int Magic(int* input_arr, int start, int end) {
		int mid = start + (end - start) / 2;

		if (input_arr[mid] == mid) {
			return mid;
		}
		else if (input_arr[mid] > mid) {
			return Magic()
		}
	}
};

int main() {
	int *input_arr = new int[20];
	srand(0);
	for (auto it = 0; it < 20; ++it) {
		input_arr[it] = rand()%100;
	}

	input_arr[10] = 10;
	input_arr[13] = 13;

	MagicNumber m1;
	int ret_idx = m1.Magic(input_arr, 0, 19);
	cout << ret_idx << endl;
}