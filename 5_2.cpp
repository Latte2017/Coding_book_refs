/*
Given a double number between 0 and 1, print number if it can be represented in binary of 32 if not print error
example:
	Decimal 0.625 = (0.101) base 2
*/

#include<string>
#include<iostream>
using namespace std;

class PartialBase {
private:
	int given_input;
public:
	PartialBase(int val) {
		given_input = val;
	}

	string ConvertToBinary() {
		string ret_val = ".";
		while (given_input) {
			if (given_input < 0 or given_input > 1) {
				return "ERROR";
			}

			if (ret_val.size() >= 32) {
				return "ERROR";
			}

			int tmp = given_input * 2;
			if (tmp > 1) {
				ret_val.append("1");
			}
			else {
				ret_val.append("0");
			}
			given_input = tmp - 1;
		}
		return ret_val;
	}
};

int main() {
	PartialBase p1(0.625);
	string ret_val = p1.ConvertToBinary();
	cout << ret_val << endl;
}


