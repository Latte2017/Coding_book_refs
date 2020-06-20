/*
Implement a function to check if a BT is BST
*/

#include <climits>
#include <iostream>

using namespace std;

class Node {
public:
	int val;
	Node* left = nullptr;
	Node* right = nullptr;

	Node(int node_val) {
		val = node_val;
	}
};

class Tree {
private:
	bool BSTHelper(Node* curr_node, int min_val, int max_val) {
		if (!curr_node) {
			return true;
		}
		if (curr_node->val <= min_val or curr_node->val >= max_val) {
			return false;
		}
		bool lval = BSTHelper(curr_node->left, min_val, curr_node->val);
		bool rval = BSTHelper(curr_node->right, curr_node->val, max_val);

		if (lval == false or rval == false) {
			return false;
		}
		return true;
	}
public:
	bool isBST(Node* root) {
		return BSTHelper(root, INT_MIN, INT_MAX);
	}
};

int main(){
	Node* root = new Node(50);
	Node* left = new Node(20);
	Node* right = new Node(60);
	root->left = left;
	root->right = right;
	Tree t1;
	bool ret_val = t1.isBST(root);
	cout << ret_val << endl;
	return 0;
}