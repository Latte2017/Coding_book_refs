/*
A magic index is A[i] = i
Given a sorted array return a magic index
*/

#include<iostream>
#include<array>
using namespace std;

class MagicNumber {
public:
	//Without any repeating numbers
	int Magic(int* input_arr, int start, int end, int arrSize) {
		
		if (start > end or start < 0 or end > arrSize) {
			return -1;
		}

		int mid = start + (end - start) / 2;

		if (input_arr[mid] == mid) {
			return mid;
		}
		else if (start == end and input_arr[mid] != mid) {
			return -1;
		}
		else if (input_arr[mid] > mid) {
			return Magic(input_arr, start, mid-1, arrSize);
		}
		else if (input_arr[mid] < mid) {
			return Magic(input_arr, mid+1, end, arrSize);
		}
	}

	//With repeating numbers
	int Magic2(int* input_arr, int start, int end, int arrSize) {

		if (start > end or start < 0 or end > arrSize) {
			return -1;
		}


		int mid = start + (end - start) / 2;
		int lidx = min(mid-1, input_arr[mid]);
		int ridx = max(mid+1, input_arr[mid]);

		if (mid == input_arr[mid]) {
			return mid;
		}
		else if (start == end) {
			return -1;
		}
		else {
			int lval = Magic2(input_arr, start, lidx, arrSize);
			int rval = Magic2(input_arr, ridx, end, arrSize);
			if (lval != -1) {
				return lval;
			}
			else if (rval != -1) {
				return rval;
			}
			else {
				return -1;
			}
		}


	}
};

int main() {
	int input_arr[] = { -40,-20,-1,1,2,3,5,7,9,12,13};
	int arrSize = sizeof(input_arr) / sizeof(input_arr[0]);
	MagicNumber m1;
	int ret_idx = m1.Magic(input_arr, 0, 10, 10);
	int ret_idx1 = m1.Magic2(input_arr, 0, 10, 10);
	cout << ret_idx1  << endl;
}