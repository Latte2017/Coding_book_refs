/*
Design a min stack which in addition to push and pop also returns min in O(1)
*/

#include<iostream>
#include<vector>

using namespace std;

class stk {
private:
	vector<int> numbers;
	vector<int> min_stk;
	int max_size;
public:
	stk(int size) {
		max_size = size;
	}

	void push(int num) {
		if (numbers.empty()) {
			numbers.push_back(num);
			min_stk.push_back(num);
		}
		else {
			numbers.push_back(num);
			int tmp_num = min_stk.back();
			if (num < tmp_num) {
				min_stk.push_back(num);
			}
			else {
				min_stk.push_back(tmp_num);
			}
		}
	}

	void pop() {
		if (numbers.empty()) {
			return;
		}
		numbers.pop_back();
		min_stk.pop_back();
	}

	int min() {
		if (numbers.empty()) {
			return -1;
		}
		return min_stk.back();
	}
};

int main() {
	stk mystk = stk(5);
	mystk.pop();
	mystk.push(3);
	cout << mystk.min() << endl;
	mystk.push(2);
	cout << mystk.min() << endl;
	mystk.push(1);
	cout << mystk.min() << endl;
	mystk.pop();
	cout << mystk.min() << endl;
}