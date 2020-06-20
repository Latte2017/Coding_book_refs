/*
Delete node in middle
	Make sure u ask if K is zero based or 1 based
*/

#include<vector>
#include <iostream>

using namespace std;

class Node {
public:
	int val;
	Node* next;
	Node(int x) {
		val = x;
	}
};

class LinkedList {
private:
	Node* curr, * prev, * head;
public:
	LinkedList(){
		Node* head = nullptr;
		Node* curr = nullptr;
		Node* prev = nullptr;
	}

	void Create(vector<int>input_vec) {
		curr = head;
		for (auto it = input_vec.begin(); it != input_vec.end(); ++it) {
			Node* tmp = new Node(*it);
			if (!head) {
				head = tmp;
			}
			else {
				curr->next = tmp;
			}
			curr = tmp;
		}
	}

	Node* DeleteFromMiddle(int k) {
		curr = head;
		prev = new Node(0);
		if (k == 1) {
			return curr->next;
		}
		while (k > 1) {
			prev = curr;
			curr = curr->next;
			k -= 1;
		}
		prev->next = curr->next;
		return head;
	}
};

int main() {
	vector<int> input_vec = { 1,2,3,4 };
	LinkedList l1;
	l1.Create(input_vec);
	Node* ret_node = l1.DeleteFromMiddle(2);
	while (ret_node) {
		cout << ret_node->val << "\t";
		ret_node = ret_node->next;
	}
}