/*
Implement a function to reverse a null pointed string
*/

#include<iostream>
#include<string>

using namespace std;


class stringManip {
private:
	string input_str;

public:
	stringManip(string input) {
		input_str = input;
	}

	string reverse() {
		string return_str;
		for (auto it = input_str.rbegin(); it != input_str.rend(); ++it) {
			if (*it != '\n') {
				return_str.push_back(*it);
			}
		}
		return return_str;
	}
};

//This passes char pointers
class stringManip2 {
private:
	char* begin;
public:
	stringManip2(char* begin) {
		this->begin = begin;
	}

	char* reverse() {
		char* end = begin;
		char* ret_begin = begin;
		while (*end) {
			end++;
		}
		end--;

		while (begin < end) {
			auto tmp = *begin;
			*begin = *end;
			*end = tmp;
			begin++;
			end--;
		}
		return ret_begin;
	}

};

int main() {
	string s = "abc";
	//First Method
	stringManip str_inst = stringManip(s.c_str());
	string return_str = str_inst.reverse();
	cout << return_str << endl;

	//Second Method
	char myString[]{ "abc" };
	stringManip2 manip2 = stringManip2(myString);
	char* return_str2 = manip2.reverse();

	while (*return_str2 != NULL) {
		cout << *return_str2;
		return_str2++;
	}
	cout << endl;

	return 0;
}