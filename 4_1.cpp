/*
Check if a binary Tree is balanced

left and right height diff less than 2

*/


#include<iostream>

using namespace std;


class Node {
public:
	int val;
	Node* left;
	Node* right;

	Node(int input_val) {
		val = input_val;
	}
};


class Tree {
private:
	Node* root;
	int height(Node* n1) {
		int lheight = 0, rheight = 0;
		if (!n1) {
			return 0;
		}

		lheight = height(n1->left);
		rheight = height(n1->right);

		return lheight + rheight + 1;
	}
public:
	Tree(Node* given_root) {
		root = given_root;
	}

	bool isBalanced() {
		int lheight = 0, rheight = 0;
		if (!root) {
			return true;
		}

		lheight = height(root->left);
		rheight = height(root->right);

		if (abs(lheight - rheight) >= 2) {
			return false;
		}
		return true;
	}
};

int main() {
	Node* root, * left, * right, * ll, * lr, * lrr;
	root = new Node(20);
	left = new Node(10);
	right = new Node(30);
	ll = new Node(5);
	lr = new Node(13);
	lrr = new Node(18);
	Tree* t1 = new Tree(root);
	cout << t1->isBalanced() << endl;
}