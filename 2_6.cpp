/*
Find the beginning of a circular linked list
*/


#include<iostream>
using namespace std;

class Node {
public:
	int val = 0;
	Node* next;
	Node* prev;
	Node(int x) {
		val = x;
	}
};


class LinkedList {
public:
	Node* findloop(Node* l1) {
		Node *slow = l1;
		Node *fast = l1;
		fast = fast->next;

		while (slow != fast) {
			slow = slow->next;
			fast = fast->next->next;
		}
		slow = l1;
		while (slow != fast) {
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}
};

int main() {
	Node head = Node(1);
	Node n1 = Node(2);
	Node n2 = Node(3);
	Node n3 = Node(4);
	Node n4 = Node(5);
	head.next = &n1;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n2;
	LinkedList l1;
	Node* ret_node = l1.findloop(&head);
	cout << ret_node->val << endl;
}