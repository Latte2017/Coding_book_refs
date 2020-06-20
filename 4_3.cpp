/*
Given a sorted array of unique elements, create a binary search tree with minimal height
*/

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node(int x) {
		val = x;
	}

};

class BST {
private:
	Node* root;
public:
	Node* Create(int* arr, int start, int end) {
		if (start > end) {
			return nullptr;
		}
		int mid = start + (end - start) / 2;
		Node* root = new Node(arr[mid]);
		root->left = Create(arr, start, mid-1);
		root->right = Create(arr, mid + 1, end);
		return root;
	}
};


int main() {
	int arr[5] = { 1, 2, 3, 4, 5 };
	BST mytree;
	Node* ret_node = mytree.Create(arr, 0, 4);
	return 0;
}