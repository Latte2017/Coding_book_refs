/*
Implement stack of stacks
	Where they act like one. Removing one element from stack1 should move all the elements from stk2 by 1.
	And adding element to stack one should move the stk2 by 1
*/

#include<iostream>
#include<vector>

using namespace std;

class stk {
private:
	vector<vector<int>> stackofstacks;
	int stk_num;
	int capacity;
public:
	stk(int max_size) {
		capacity = max_size;
		stk_num = 0;
		vector<int> tmp;
		stackofstacks.push_back(tmp);
	}

	void push(int num) {
		if (stackofstacks[stk_num].size() == capacity) {
			vector<int> tmp;
			stackofstacks.push_back(tmp);
			stk_num++;
		}

		stackofstacks[stk_num].push_back(num);
	}

	int pop() {
		int return_num = stackofstacks[stk_num].back();
		stackofstacks[stk_num].pop_back();
		if (stackofstacks[stk_num].size() == 0) {
			stackofstacks.pop_back();
			stk_num--;
		}
		return return_num;
	}
};


int main() {
	int capacity = 10;
	stk mystack = stk(10);
	for (auto it = 0; it < 30; ++it) {
		mystack.push(it);
	}

	for (auto it = 0; it < 10; ++it) {
		mystack.pop();
	}

	return 0;
}