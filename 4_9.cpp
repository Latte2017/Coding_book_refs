/*
Given a Binary tree. Print all the paths to a given sum. The path doesnt need to start or end at root or leaf
Solution:
	1) Use pre order traversal
	2) If path == sum at this node print path
*/
#include<vector>
#include <iostream>

using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node(int val) {
		this->val = val;
	}
};

class Tree {
private:
	void PrintPath(vector<int> currentSum) {
		for (auto it = currentSum.begin(); it != currentSum.end(); ++it) {
			cout << *it << '\t';
		}
		cout << endl;
	}
public:
	void pathSum(Node* root, vector<int> currentSum, int result) {
		if (!root) {
			return;
		}
		currentSum.push_back(root->val);
		int tmp_sum = 0;
		for (auto it = currentSum.begin(); it != currentSum.end(); ++it) {
			tmp_sum += *it;
		}

		if (tmp_sum == result) {
			PrintPath(currentSum);
		}

		if (root->left) {
			pathSum(root->left, currentSum, result);
		}
		if (root->right) {
			pathSum(root->right, currentSum, result);
		}
		currentSum.pop_back();
	}
};