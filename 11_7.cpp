/*
Given height and weight, Construct the tallest tower.
The person above should be less than the person below in both height and weight
(65,100), (70, 150), (56, 90)
*/
#include<tuple>
#include<vector>
#include <algorithm>
using namespace std;

class Construct {
	//Sort 3 arg should be a static  
	static bool CompareByHeight(const pair<int, int>& a, const pair<int, int>& b) {
		return (a.first < b.first);
	}

	static bool CompareByWeight(const pair<int, int>& a, const pair<int, int>& b) {
		return (a.second < b.second);
	}

	vector<pair<int, int>> FindLIS(vector<pair<int, int>>& v1, vector<pair<int, int>>& v2, int m, int n) {

		if (v1[m] == v2[n]) {

		}
	}

public:
	pair<int, int> Tallest(vector<pair<int, int>>& input_vec) {
		pair<int, int> ret_pair = { 0,0 };
		vector<pair<int,int>> sort_by_height = input_vec;
		vector<pair<int, int>> sort_by_weight = input_vec;
		//Cant use sort (11,50) (13,23) For these it wont sort
		sort(sort_by_height.begin(), sort_by_height.end(), CompareByHeight);
		sort(sort_by_weight.begin(), sort_by_weight.end(), CompareByWeight);
		
		//Find the largest increasing subsequence of the 2 vectors.

		FindLIS(sort_by_height, sort_by_weight, sort_by_height.size()-1, sort_by_weight.size()-1);

		return ret_pair;
	}
};


int main() {
	vector<pair<int, int>> input_vec = { {65,100}, {70, 150}, {56, 90} };
	Construct c1;
	pair<int, int> tallest = c1.Tallest(input_vec);


}
