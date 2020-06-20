/*
Write a method to replace all spaces with %20. Do inplace
"Mr Smith  "
"Mr%20Smith"
*/

#include<iostream>

using namespace std;

class stringManip {
private:
	string input_str;
public:
	stringManip(string s1) {
		this->input_str = s1;
	}

	string strInplace() {
		string toreplace = "%20";
		bool flag = false;
		int actual_end = input_str.size()-1;
		for (int index = input_str.size()-1; index >= 0; index--) {
			if (isspace(input_str[index]) and flag == false){
				continue;
			}
			flag = true;
			if (not isspace(input_str[index])) {
				input_str[actual_end] = input_str[index];
				actual_end--;
			}
			else {
				input_str[actual_end] = '0';
				input_str[actual_end-1] = '2';
				input_str[actual_end-2] = '%';
				actual_end -= 3;

			}
		}
		return input_str;
	}
};

int main() {
	string s1 = "Mr and Smith    ";
	stringManip manip = stringManip(s1);
	string ret_val = manip.strInplace();
	cout << ret_val << endl;
	return 0;
}