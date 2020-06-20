/*
Given a depth return a linked list of all the nodes at all levels
*/

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Node {
public:
	int val;
	Node* left = nullptr;
	Node* right = nullptr;
	Node* next = nullptr;
	Node(int x) {
		val = x;
	}
};

class LinkedList {
public:
	Node* head = nullptr;
	Node* curr = nullptr;
	LinkedList(Node* curr_head) {
		head = curr_head;
	}
};
class Tree {
private:
	Node* root;
	vector<LinkedList> level_ll;
	void levelHelper(int level, Node* curr_node) {
		if (!curr_node) {
			return;
		}
		if (level_ll.size() <= level) {
			level_ll.push_back(curr_node);
			level_ll[level].curr = curr_node;
		}
		else {
			level_ll[level].curr->next = curr_node;
			level_ll[level].curr = curr_node;
		}
		levelHelper(level + 1, curr_node->left);
		levelHelper(level + 1, curr_node->right);
	}
public:
	Tree(Node* root_node) {
		root = root_node;
	}
	

	vector<LinkedList> Level() {
		levelHelper(0, root);
		return level_ll;
	}
};


int main() {
	Node* head = new Node(50);
	Node* left = new Node(30);
	Node* right = new Node(80);
	Node* ll = new Node(15);
	Node* lr = new Node(40);
	Node* lll = new Node(10);
	head->left = left;
	head->right =  right;
	head->left->left = ll;
	head->left->right = lr;
	head->left->left->left = lll;

	Tree t1 = Tree(head);

	vector<LinkedList> ret_lists = t1.Level();

	for (auto it = ret_lists.begin(); it != ret_lists.end(); ++it) {
		LinkedList l1 = *it;
		l1.curr = l1.head;
		while(l1.curr){
			cout << (l1).curr->val << "\t";
			l1.curr = l1.curr->next;
		}
		cout << endl;
	}

}