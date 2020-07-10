/*
Compute all permutations of string
*/

#include<iostream>
#include<vector>
#include<string>


using namespace std;


class Permute {
private:
	vector<string> permuteHelper(string input, int lower, int upper) {
		vector<string> ret_vec;
		if (lower == upper) {
			ret_vec.push_back(input);
			return ret_vec;
		}
		for (int i = lower; i < upper; ++i) {

			swap(input[i], input[lower]);

			vector<string> tmp_vec = permuteHelper(input, lower + 1, upper);
			ret_vec.insert(ret_vec.end(),tmp_vec.begin(), tmp_vec.end());

			swap(input[lower], input[i]);
		}
		return ret_vec;
	}
public:
	vector<string> getPermute(string input) {
		return permuteHelper(input, 0, input.size() - 1);
		
	}
};

int main() {
	string input = "ABCD";
	Permute p1;
	vector<string> ret_vec = p1.getPermute(input);
	for (int i = 0; i < ret_vec.size(); ++i) {
		cout << ret_vec[i] << endl;
	}
	return 0;
}