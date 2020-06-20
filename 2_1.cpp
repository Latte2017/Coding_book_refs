/*
Remove duplicates from unsorted linked list

Mistake1 prev pointer shouldnt be updated if we find the value this is to prevent 
1 - 1 - 1 - 1  
*/

#include<vector>
#include <iostream>
#include <set>

using namespace std;

class Node {
public:
	int val;
	Node* next;
	Node(int x) {
		this->val = x;
		this->next = nullptr;
	}
	Node() {
		this->val = 0;
		this->next = nullptr;
	}
};

class LinkedList {
private:
	Node* head;
	Node* cur;
public:
	LinkedList() {
		head = nullptr;
		cur = nullptr;
	}
	void insertInto(int value) {
		Node* newNode = new Node(value);
		if (head) {
			cur->next = newNode;
		}
		else {
			head = newNode;
		}
		cur =  newNode;
	}

	void create(vector<int> input_vec) {
		for (auto& x : input_vec) {
			insertInto(x);
		}
		
	}
	//Remove duplicates without extra DS. O(n^2) solution.
	Node* removeduplicates() {
		Node *curr = head;
		Node *nextptr = nullptr, *prev = nullptr;
		while (curr) {
			prev = curr;
			nextptr = curr->next;
			while (nextptr) {
				if (nextptr->val == curr->val) {
					prev->next = nextptr->next;
				}
				else {
					prev = nextptr;
				}
				nextptr = nextptr->next;
			}
			curr = curr->next;
		}
		return head;
	}

	//Remove duplicates with DS
	Node* removeduplicates2() {
		Node* curr = head;
		Node* prev = nullptr;
		set<int> uniq;
		while (curr) {
			if (uniq.find(curr->val) != uniq.end()) {
				prev->next = curr->next;
			}
			else {
				uniq.insert(curr->val);
				prev = curr;
			}
			curr = curr->next;
		}
		return head;
	}
};


int main() {
	vector<int> input_vec = { 1,1,1,1,1,3,3,4,5,1 };
	// Automatically create linkedlist list<int> ll(input_vec.being(), inpput_vec.end());
	LinkedList l1 = LinkedList();
	l1.create(input_vec);
	Node *ret_node = l1.removeduplicates2();
	while (ret_node) {
		cout << ret_node->val << '\t';
		ret_node = ret_node->next;
	}
	return 0;
}