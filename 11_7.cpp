/*
Given height and weight, Construct the tallest tower.
The person above should be less than the person below in both height and weight
(65,100), (70, 150), (56, 90)
*/
#include<tuple>
#include<vector>
#include <algorithm>
using namespace std;

pair<int, int> operator +(const std::pair<int, int>& x, const std::pair<int, int>& y) {
	return { x.first + y.first, x.second + y.second };
}

class Construct {
	vector<pair<int, int>> subsequence;
	pair<int, int> max_pair;
	
	//Sort 3 arg should be a static  
	static bool CompareByHeight(const pair<int, int>& a, const pair<int, int>& b) {
		return (a.first < b.first);
	}

	//nlogn algo
	int LIS(vector<vector<int>>& envelopes) {
		int begin = 0, end = 0;
		int mid = 0;
		vector<int> subsequence;
		for (auto it = envelopes.begin(); it != envelopes.end(); ++it) {
			begin = 0;
			while (begin < end) {
				mid = begin + (end - begin) / 2;
				if (subsequence[mid] < (*it)[1]) {
					begin = mid + 1;
				}
				else {
					end = mid;
				}
			}
			if (subsequence.size() > begin) {
				subsequence[begin] = (*it)[1];
			}
			else {
				subsequence.push_back((*it)[1]);
			}
			end = subsequence.size();
		}
		return end;
	}


	void FindLIS(vector<pair<int, int>>& v1, int i, int j) {
		//https://www.youtube.com/watch?v=CE2b_-XfVDk
		// time complexity = N^2 
	
		if (v1.size() == i) {
			return;
		}

		if (i == j) {
			FindLIS(v1, i + 1, 0);
		}
		else if (i > j) {
			if (v1[i] > v1[j]) {
				subsequence[i] = subsequence[i] + v1[j];
				if (subsequence[i] > max_pair) {
					max_pair = subsequence[i];
				}
			}
			
			FindLIS(v1, i, j + 1);
		}
		
		
		return;	 
	}

public:

	Construct() {
		max_pair = { 0,0 };
	}

	pair<int, int> Tallest(vector<pair<int, int>>& input_vec) {
		
		//Cant use sort (11,50) (13,23) For these it wont sort
		sort(input_vec.begin(), input_vec.end(), CompareByHeight);
		subsequence = input_vec;
		
		//Find the largest increasing subsequence of the 2 vectors.
		int i = 1;
		int j = 0;
		FindLIS(input_vec, 1, 0);
		
		return max_pair;
	}
};


int main() {


	vector<pair<int, int>> input_vec = { {65,100}, {70, 150}, {56, 90}, {75,190}, {60, 95}, {68,110} };
	Construct c1;
	pair<int, int> tallest = c1.Tallest(input_vec);


}
