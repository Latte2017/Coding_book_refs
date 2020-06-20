/*
Given two strings find if one is a permutation of another
*/

#include<iostream>
#include<algorithm>
#include <vector>

using namespace std;

class Permute {
private:
	string s1, s2;
public:
	Permute(string s1, string s2) {
		this->s1 = s1;
		this->s2 = s2;
	}

	bool isPermute() {
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());

		if (s1 == s2) {
			return true;
		}
		return false;
	}

	bool isPermute2() {
		vector<int>count(256, 0);

		for (string::iterator it = s1.begin(); it != s1.end(); ++it) {
			count[*it - 'A'] ++;
		}

		for (string::iterator it = s2.begin(); it != s2.end(); ++it) {
			count[*it - 'A'] --;
		}

		for (int i = 0; i < 256; ++i) {
			if (count[i] != 0){
				return false;
			}
		}
		return true;
	}
};


int main() {
	string s1 = "acda";
	string s2 = "dca";
	Permute per = Permute(s1, s2);
	bool p1 = per.isPermute();
	bool p2 = per.isPermute2();
	if (p1 != p2) {
		cout << "Failed " << p1 << endl;
		return false;
	}
	cout << "Passed " << p1 << endl;
	return true;
}