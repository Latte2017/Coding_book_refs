/*
Implement queue using 2 stacks

FIFO

front<-1-2-3->back

BY making enque costly 
	1) Push everything from stack1 into stack2
	2) insert element 1 into stack1
	3) push everything back into stack1
*/

#include<stack>
#include <iostream>

using namespace std;

class stk {
private:
	stack<int> s1, s2;

public:
	void push(int x) {
		if (s1.empty()) {
			s1.push(x);
		}
		else {
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
			s1.push(x);
			while (!s2.empty()) {
				s1.push(s2.top());
				s2.pop();
			}
		}
	}


	int pop() {
		if (s1.empty()) {
			return -1;
		}
		int ret_val = s1.top();
		s1.pop();
		return ret_val;
	}
};


int main() {
	stk s1;
	s1.push(4);
	s1.push(3);
	s1.push(2);
	cout << s1.pop() << endl;
	return 0;
}