/*
Given an array of strings. Sort such that anagrams are in order
*/

#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;


class ArrayOfStrings {
public:
	vector<string> SortStrings(vector<string>& input_vec) {
		unordered_map<string, vector<string>> map1;
		vector<string> ret_vec;
		for (auto it = input_vec.begin(); it != input_vec.end(); ++it) {
			string tmp_wrd = *it;
			vector<string> tmp_vec;
			sort((tmp_wrd).begin(), (tmp_wrd).end());
			map1[tmp_wrd].push_back(*it);
		}

		for (auto it = map1.begin(); it != map1.end(); ++it) {
			for (auto ix = (it->second).begin(); ix != (it->second).end(); ++ix) {
				ret_vec.push_back(*ix);
			}
		}
		return ret_vec;
	}
};

int main() {
	vector<string> input_vec = { "abc", "cat", "cab", "def", "kli" };
	ArrayOfStrings a1;
	vector<string> ret_vec = a1.SortStrings(input_vec);
}