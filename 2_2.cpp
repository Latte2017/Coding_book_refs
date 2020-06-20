/*
Find the kth element from end
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
	Node* head;
	Node* curr;
public:
	LinkedList(vector<int> input) {
		Node *tmp = nullptr;
		for (vector<int>::iterator it = input.begin(); it != input.end(); ++it) {
			tmp = new Node(*it);
			if (head) {
				curr->next = tmp;
			}
			else {
				head = tmp;
			}
			curr = tmp;
		}
	}

	Node* findKth(int k) {
		Node* slow = head;
		Node* fast = head;

		while (k>0) {
			fast = fast->next;
			k -= 1;
		}
		if (fast == nullptr) {
			return nullptr;
		}

		while (fast) {
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}
};

int main() {
	vector<int> input = { 1,2,3,4,5 };
	int k = 3;
	LinkedList l1 = LinkedList(input);
	Node* ret_node = l1.findKth(k);
	cout << "Kth node is " << ret_node->val << endl;
}