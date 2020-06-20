/*
Implement a stack
*/
#include<vector>
#include <iostream>

using namespace std;

class stak {
private:
	vector<int> stk;
public:
	void Insert(vector<int> input) {
		for (auto it = input.begin(); it != input.end(); ++it) {
			stk.push_back(*it);
		}
	}
	void pop() {
		if (!stk.empty()) {
			return stk.pop_back();
		}
		else {
			return;
		}
	}

	void push(int x) {
		stk.push_back(x);
	}

	void display() {
		for (auto it = stk.begin(); it != stk.end(); ++it) {
			cout << *it << '\t';
		}
	}
};


int main() {
	vector<int> input = { 1,2,3,4 };
	stak s1;
	s1.Insert(input);
	s1.display();
	s1.pop();
	s1.display();
	s1.push(6);
	s1.display();

}

