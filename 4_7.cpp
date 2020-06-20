/*
Find the LCA of a binary tree
*/

#include <tuple>
#include <iostream>

using namespace std;
class Node {
public:
	int val;
	Node* left = nullptr;
	Node* right = nullptr;

	Node(int val) {
		this->val = val;
	}
};

class BinaryTree {
private:
	bool IfExists(Node* curr, Node* n3) {
		if (curr == n3) {
			return true;
		}
		if (curr->left and (IfExists(curr->left, n3))) {
			return true;
		}
		if (curr->right and (IfExists(curr->right, n3))) {
			return true;
		}
		return false;
	}


	tuple<Node*, int> recur(Node* curr, Node* n1, Node* n2) {
		tuple<Node*, int> ret_val_n1 = make_tuple(nullptr, 0), ret_val_n2 = make_tuple(nullptr, 0);
		if (!curr) {
			return make_tuple(nullptr, 0);
		}
		if ((curr == n1)){
			if (IfExists(curr, n2)) {
				return make_tuple(curr, 2);
			}
			else {
				return make_tuple(curr, 1);
			}
		}
		if ((curr == n2)) {
			if (IfExists(curr, n1)) {
				return make_tuple(curr, 2);
			}
			else {
				return make_tuple(curr, 1);
			}
		}
		if (curr->left) {
			ret_val_n1 = recur(curr->left, n1, n2);
			if (get<1>(ret_val_n1) ==2) {
				return ret_val_n1;
			}
		}
			
		if (curr->right){
			ret_val_n2 = recur(curr->right, n1, n2);
			if (get<1>(ret_val_n2) ==2) {
				return ret_val_n2;
			}
		}

		if (get<1>(ret_val_n1) == 1 and get<1>(ret_val_n2) == 1) {
			return make_tuple(curr, 2);
		}
		else if (get<1>(ret_val_n2) == 1) {
			return ret_val_n2;
		}
		else if (get<1>(ret_val_n1) == 1) {
			return ret_val_n1;
		}

		return make_tuple(nullptr, 0);

	}

public:
	Node* LCA(Node* root, Node* node1, Node* node2) {
		int ret_val = 0;
		tuple<Node*, int>val_l, val_r;
		if (root and root == node1) {
			if (IfExists(root, node2)) {
				return root;
			}
			return nullptr;
		}
		else if (root and root == node2) {
			if (IfExists(root, node1)) {
				return root;
			}
		}
		else {
			val_l = recur(root, node1, node2);
			if (get<1>(val_l) == 2 ){
				return root;
			}
		}
		return nullptr;


	}
};

int main() {
	Node* root, * left, * right, * ll, * lr, * lrr, *rr;
	root = new Node(20);
	left = new Node(10);
	right = new Node(30);
	ll = new Node(5);
	lr = new Node(13);
	lrr = new Node(18);
	rr = new Node(40);
	root->left = left;
	root->right = right;
	left->left = ll;
	left->right = lr;
	lr->right = lrr;
	right->right = rr;
	BinaryTree btree;
	Node* common = btree.LCA(root, lr, rr);
	cout << common->val  << endl;
}