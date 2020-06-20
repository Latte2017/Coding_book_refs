/*
Partition around x. Any value less than x should be towards left and greater than should be right
*/

#include <forward_list>
#include<iostream>
#include <vector>
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
	Node* head, * curr, * nxt;
public:
	LinkedList(vector<int> v1) {
		head = nullptr;
		curr = nullptr;
		nxt = nullptr;
		for (auto it = v1.begin(); it != v1.end(); ++it) {
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

	//Create 2 nodes and add less than values to one node and greater than values 
	//to other node and join
	Node* partition(int partition_variable) {
		Node* h1 = new Node(0);
		Node* runner1 = h1;
		Node* h2 = new Node(0);
		Node* runner2 = h2;
		Node* h3 = new Node(0);
		Node* runner3 = h3;
		curr = head;
		while (curr) {
			if (curr->val < partition_variable) {
				runner1->next = curr;
				runner1 = runner1->next;
			}
			else if (curr->val > partition_variable) {
				runner2->next = curr;
				runner2 = runner2->next;
			}
			else {
				runner3->next = curr;
				runner3 = runner3->next;
			}
			curr = curr->next;
		}
		runner1->next = h3->next;
		runner3->next = h2->next;
		return h1->next;
	}

};

int main() {
	vector<int> v1 = { 1,2,5,2,3,4 };
	LinkedList l1(v1);
	Node* ret_node = l1.partition( 3);
	while (ret_node) {
		cout << ret_node->val << '\t';
		ret_node = ret_node->next;
	}
}