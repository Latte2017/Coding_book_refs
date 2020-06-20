/*
Find if a tree is subtree of another
*/

#include<iostream>
#include<vector>
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

class Tree {
private:
	vector<Node*> starting_nodes;
	void Find(Node* root1, Node* root2) {
		if (!root1) {
			return;
		}
		if (root1->val == root2->val) {
			starting_nodes.push_back(root1);
		}
		if (root1->left) {
			Find(root1->left, root2);
		}
		if (root1->right) {
			Find(root1->right, root2);
		}
	}

	bool IsSame(Node* root1, Node* root2) {
		if (root1 == root2){
			if (root1->left) {
				if (!IsSame(root1->left, root2->left)) {
					return false;
				}
			}
			if (root1->right) {
				if (!IsSame(root1->right, root2->right)) {
					return false;
				}
			}
			return true;
		}
		return false;
	}
public:
	bool IsSubTree(Node* root1, Node* root2) {
		Find(root1, root2);

		for (auto it = starting_nodes.begin(); it != starting_nodes.end(); ++it) {
			if (IsSame(*it, root2)) {
				return true;
			}
		}
		return false;
	}
};

int main() {
	Node* root, * left, * right, * ll, * lr, * lrr, * rr;
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

	Tree *t1 = new Tree();
	bool ret_val = t1->IsSubTree(root, ll);
	return 0;
}