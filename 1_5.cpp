/*
Implement basic string compression
aaabbccc= a3b2c3

if the returned string is larger than or equal to original string return original
*/

#include<iostream>
#include<string>
#include <vector>
#include <sstream>

using namespace std;

class stringManip {
private:
	string input_str;
public:
	stringManip(string s1) {
		input_str = s1;
	}
	string stringCompress() {
		vector<int> v1(256);
		string ret_str = "";
		for (string::iterator it = input_str.begin(); it != input_str.end(); ++it) {
			v1[*it - 'A'] += 1;
		}

		for (int iter = 0; iter < 256; ++iter) {
			if (v1[iter] != 0){
				ret_str.push_back(iter + 'A');
				ret_str.append(to_string(v1[iter]));
			}
		}

		if (ret_str.size() >= input_str.size()) {
			return input_str;
		}
		return ret_str;
	}
};


int main() {
	string s1 = "aaaaaaaaaaaaaaaaaaaaaaaabbbbcd";
	stringManip m1 = stringManip(s1);
	string ret_str = m1.stringCompress();
	cout << ret_str << endl;
	return 0;
}