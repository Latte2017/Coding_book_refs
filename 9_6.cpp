/*
Given a number generate valid paranthesis
n = 1
()

n=2
(())
()()


*/

#include<iostream>
#include<set>
#include<string>
#include<stack>
using namespace std;

class generate {
private:
	set<string> return_str;

	bool isvalid(string input_param) {
		stack<string> tmp_stk;
		for (auto it = input_param.begin(); it != input_param.end(); ++it) {
			if (*it == '(') {
				tmp_stk.push("(");
			}
			else if (!tmp_stk.empty() and tmp_stk.top() == "("){
				tmp_stk.pop();
			}
			else {
				return false;
			}
		}
		if (tmp_stk.empty()) {
			return true;
		}
		return false;
	}


	void paranRecur(int num, int left, int right,  string runner) {
		if (num == left + right) {
			if (isvalid(runner)) {
				return_str.insert(runner);
			}
			return;
		}
		else if (left + right - 1 < num) {
			paranRecur(num, left + 1, right, runner + '(');
			paranRecur(num, left, right + 1, runner + ')');
		}
		else {
			return;
		}
	}
public:
	set<string> Paranthesis(int num) {
		paranRecur(num*2, 0, 0, "");
		return return_str;
	}
};


int main() {
	generate g1;
	set<string> ret = g1.Paranthesis(2);

}