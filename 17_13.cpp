/*
Consider a simple node like

class BiNode{
	Binode n1, n2;
	int data;
}

Given a BST Convert into a double linked list

						4
				2			5
			1		3	NULL		6
		0				

		0<->1<->2<->3<-4->5<->6
*/

class DLL;

class Node {
	friend class DLL;
public:
	int data =0;
	Node* left = nullptr, *right = nullptr;
	Node() {};
	Node(int val) {
		data = val;
		left = nullptr;
		right = nullptr;
	}

	virtual ~Node() {};
};


class DLL {
public:
	DLL* Prev = nullptr, * Next = nullptr;
	DLL() {
		Prev = nullptr;
		Next = nullptr;
	}

	
};

class Convert {
public:
	Node* BstToDll(Node* root) {
		Node* prev = nullptr, *nnext = nullptr;
		if (!root) {
			return nullptr;
		}

		if (root->left) {
			prev = BstToDll( root->left);
			while (prev->right) {
				prev = prev->right;
			}
			prev->right = root;
			root->left = prev;
		}
		else {
			root->left = nullptr;
		}
		

		if (root->right) {
			nnext = BstToDll(root->right);

			while (nnext->left) {
				nnext = nnext->left;
			}
			nnext->left = root;
			root->right = nnext;
		}
		else {
			root->right = nullptr;
		}
		return root;
	}
	
	DLL* BstToDll(Node* root, DLL* head) {
		if (!root) {
			return nullptr;
		}

		if (root->left) {
			BstToDll(root->left, head);
		}
		DLL* curr = dynamic_cast<DLL*> (root);
		head->Next = curr;
		curr->Prev = head;
		head = head->Next;
		if (root->right) {
			BstToDll(root->right, head);
		}

	}
};




int main() {
	
	Node* root = new Node(4);
	root->left = new Node(2);
	root->right = new Node(5);
	root->left->left = new Node(1);
	root->left->left->left = new Node(0);
	root->left->right = new Node(3);
	root->right->right = new Node(6);

	Convert c1;
	/*
	//Method 1
	c1.BstToDll(root);
	Node* start = root;
	while (start->left) {
		start = start->left;
	}
	*/

	//Method 2
	DLL* Head = new DLL();
	c1.BstToDll(root, Head);

}