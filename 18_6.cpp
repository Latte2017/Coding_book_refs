/*
Get the smallest 1 million numbers in one billion numbers
*/

#include<vector>
#include<queue>
#include <iostream>
using namespace std;


priority_queue<int> GetSmallest(vector<int>& arr, int n) {
	priority_queue<int> pq1;
	int i = 0;
	for (int iter = 0; iter < arr.size(); ++iter) {
		if (pq1.size() < n) {
			pq1.push(arr[iter]);
		}
		else {
			pq1.push(arr[iter]);
			pq1.pop();
		}

	}

	return pq1;
}

int main() {
	vector<int> arr = { 3,5,61,2,66, 78 };
	int n = 4;
	auto pq1 = GetSmallest(arr, n);

}