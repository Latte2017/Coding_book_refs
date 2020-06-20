/*
Determine if a string has all unique chars
*/

#include<iostream>
#include <vector>
#include<algorithm>

using namespace std;

class uniq
{
private:
	string input_str;
public:
	uniq(string input) {
		input_str = input;
	}
	bool isUniq() {
		vector<bool> characters(26, 0);
		for (auto ch= input_str.begin(); ch != input_str.end(); ++ch) {
			if (characters[*ch - 'a']){
				return false;
			}
			else {
				characters[*ch - 'a'] = true;
			}
		}
		return true;
	}

	/*Without additional data structure*/
	bool isUniq2() {
		sort(input_str.begin(), input_str.end());
		char prev = NULL;
		for (auto ch = input_str.begin(); ch != input_str.end(); ++ch) {
			if (*ch == prev){
				return false;
			}
			else {
				prev = *ch;
			}
		}
		return true;
	}
};



int main() {
	auto ret = uniq("abc");
	bool ret_val = ret.isUniq();
	cout << ret_val << endl;
	return 0;
}
