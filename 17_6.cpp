/*
Given an array write a metod to find indices m, n such that
if you sorted m--n the whole array will be sorted

20,2,4,7,10,11, 7, 12, 6 ,7, 16, 18, 19

minimize m - n
*/
#include<tuple>
#include<vector>
#include <algorithm>
#include <queue>
using namespace std;

class Sorted {

public:
	//https://www.geeksforgeeks.org/minimum-length-unsorted-subarray-sorting-which-makes-the-complete-array-sorted/
	pair<int, int> VecSort2(vector<int>& input_vec) {
		int start = 0, end = 0;

		//Find Start
		//2 3 4 5
		for (auto it = 1; it != input_vec.size(); ++it) {
			if ( input_vec[it -1] > input_vec[it]) {
				start = it - 1;
				break;
			}
		}

		//Find end
		for (auto it = input_vec.size()-1; it != 0; --it) {
			if (input_vec[it - 1] > input_vec[it]) {
				end = it;
				break;
			}
		}

		//Find max and min of the sub array
		int max = input_vec[end], min = input_vec[start];
		for (auto it = start; it < end + 1; ++it) {
			if (input_vec[it] > max) {
				max = input_vec[it];
			}
			if (input_vec[it] < min) {
				min = input_vec[it];
			}
		}

		//Find the first element to the left of begin greater than min from 0
		for (auto it = 0; it != start; ++it) {
			if (input_vec[it] > min) {
				start = it;
				break;
			}
		}

		//Find the first element from the right end less than max
		for (auto it = input_vec.size()-1; it > end; --it) {
			if (input_vec[it] < max) {
				end = it;
				break;
			}
		}
	
		return make_pair(start, end);

	}


	// Using Priotity Queue
	pair<int, int> VecSort(vector<int> input_vec) {
		pair<int, int> indices = {-1,-1};
		priority_queue<int, vector<int>, greater<int>> pq;
		
		for (int x : input_vec) {
			pq.push(x);
		}
		
			
		for (int i = 0; i < input_vec.size(); ++i) {
			
			if (pq.top() != input_vec[i]) {
				if (indices.first == -1) {
					indices.first = i;
				}
				else {
					indices.second = i;
				}
			}
			pq.pop();
			
		}
		return indices;
	}
};

int main() {
	Sorted s1;
	vector<int> input = { 20,2,4,7,10,11, 7, 12, 6 ,7, 16, 18, 19 };
	pair<int,int> res = s1.VecSort(input);
	pair<int, int> res1 = s1.VecSort2(input);
}