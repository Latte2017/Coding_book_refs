
#include<string>
#include <iostream>

using namespace std;
class Rotation {
public:
	bool isRotated(string& s1, string& s2) {
		string s3 = s1 + s1;
		string s4 = s3.substr(s2.size());
		if (s4 == s2) {
			return true;
		}
		for (int i = s2.size(); i < s3.size(); ++i ) {
			s4 = s4.substr(1) + s3[i];
			if (s4 == s2) {
				return true;
			}
		}

		return false;
		return false;
	}
};

int main() {
	Rotation r1 = Rotation();
	string s1 = "abc", s2 = "cab";
	bool ret_val = r1.isRotated(s1,s2);
	cout << ret_val << endl;
	return 0;

}