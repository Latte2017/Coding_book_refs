/*
Create 3 stacks using a vector
*/

#include<iostream>
#include<vector>
using namespace std;

class Muliplestacks {
	int* arr; //TO store the elements size is n
	int* top; // To store the top of each stack (size is number of elements)
	int* next; // To store next location of each stack
	int free; // to store the next free spot
public:
	Muliplestacks(int num_stacks, int num_elements) {
		arr = new int[num_elements];
		top = new int[num_stacks];
		next = new int[num_elements];

		for (auto it = 0; it < sizeof(top) / sizeof(top[0]); ++it) {
			top[it] = -1;
		}

		free = 0;
		for (auto it = 0; it < num_elements; ++it) {
			next[it] = it+1;
		}
		next[num_elements - 1] = -1;
	}

	bool isFull() {
		return (free == -1);
	}

	void push(int stk_num, int num) {
		if (isFull()) {
			return;
		}
		int i = free; //Store the index of first free slot
		free = next[i]; //Update the slot to next free slot
		next[i] = top[stk_num]; //update the next of top
		top[stk_num] = i; //update the top of stack
		arr[i] = num; // insert number

	}


	void pop(int stk_num) {
		if (top[stk_num] == -1) {
			return;
		}

		int nxt = next[top[stk_num]];
		top[stk_num] = nxt;
		next[nxt] = free;
		free = nxt;
	}

};


int main() {
	Muliplestacks* m1 = new Muliplestacks(3, 10);
	m1->push(1, 3);
	m1->push(1, 4);

	m1->push(2, 30);
	m1->push(2, 40);
	m1->push(2, 50);
	
	m1->push(3, 300);
	m1->push(3, 400);

	m1->pop(1);
	m1->pop(2);
	m1->pop(3);

	return 0;
}