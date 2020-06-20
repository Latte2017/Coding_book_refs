/*
Find the next node of a given node in order traversal of BST. Each node has a link to its ancestor

Inorder Successor of an input node can also be defined as the node with the smallest 
key greater than the key of the input node

https://www.geeksforgeeks.org/inorder-successor-in-binary-search-tree/


					20
				8		22
			4		12
				10		14

Inorder: 4, 8, 10, 12, 14, 20, 22 left, root, right
Preorder: 20, 8, 4, 12, 10, 14, 22 root, left, right
Postorder: 4, 10, 14, 12, 8, 22 left, right, root

In order successor of 8 is 10, 14 is 20, 22 is NULL, 4 is 8
	Algo
	1) If node has right go right
		a)	then left all the way 
	2) If node doesnt have right we need to go to its ansector 
		a) Until the ancestor is a left child of its ancestor. This ansector is the value
	Basically we need to find the next greater value than the curr value

*/

#include <iostream>

using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* parent;
	Node(int val) {
		this->val = val;
	}
};

class Tree {
private:
	Node* root;
public:
	Tree(Node* curr_head) {
		root = curr_head;
	}

	//using parent node. 
	Node* inOrderSuccesor(Node* curr) {
		Node* next_node = nullptr;

		if (curr->right) {
			next_node = curr->right;
		}
		while (next_node and next_node->left) {
			next_node = next_node->left;
		}

		if (next_node) {
			return next_node;
		}

		while (true) {
			next_node = curr->parent;
			if (next_node->parent and next_node == next_node->parent->left) {
				break;
			}
			else if (next_node->parent == nullptr) {
				return nullptr;
			}
			curr = next_node;
		}
		return next_node->parent;
	}

	// Not using parent node
	Node* inOrderSuccesor2(Node* curr) {
		Node* runner = root;
		Node* prev = nullptr;
		
		while (runner) {
			if (runner->val > curr->val) {
				prev = runner;
				runner = runner->left;
			}
			else {
				runner = runner->right;
			}
		}
		return prev;
	}


};


int main() {
	Node* head = new Node(20);
	Node* l = new Node(8);
	Node* r = new Node(22);
	Node* ll = new Node(4);
	Node* lr = new Node(12);
	Node* lrl = new Node(10);
	Node* lrr = new Node(14);
	
	head->left = l;
	head->right = r;
	l->parent = head;
	r->parent = head;
	l->left = ll;
	ll->parent = l;
	l->right = lr;
	lr->parent = l;
	lr->left = lrl;
	lrl->parent = lr;
	lr->right = lrr;
	lrr->parent = lr;

	Tree* t1 = new Tree(head);
	Node* successor = t1->inOrderSuccesor(lrr);
	Node* successor2 = t1->inOrderSuccesor2(l);

	cout << successor->val << endl;

	cout << successor2->val << endl;

}
