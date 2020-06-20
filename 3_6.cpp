/*
Sort a stack with just one additional stack

*/

#include<stack>
#include <iostream>

using namespace std;

class SortedStack {
private:
	stack<int> s1, s2;

public:

	//Max on top
	void push(int x) {
		if (s1.empty()) {
			s1.push(x);
		}
		else {
			int top = s1.top();
			while (top > x) {
				s2.push(top);
				s1.pop();
				top = s1.top();
			}
			s1.push(x);
			while (!s2.empty()) {
				s1.push(s2.top());
				s2.pop();
			}
		}
	}


	int pop() {
		int ret_val = s1.top();
		s1.pop();
		return ret_val;
	}
};

int main() {
	SortedStack s1;
	s1.push(10);
	s1.push(3);
	s1.push(2);
	cout << s1.pop() << endl;
}