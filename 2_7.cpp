/*
Check if a linkedlist is pallindrome
	Solution:
		use fast and slow pointers and insert slow pinters into stack
		When fast reaches end slow reached middle
		compare the elements with top of the stack
		For odd length stack make sure to skip one in the middle if it doesnt match
	Make sure to check for fast and fast->next while iterating
*/

#include<vector>
#include <stack>
#include <iostream>

using namespace std;
class Node {
public:
	int val;
	Node* next;
	Node(int x) {
		val = x;
	}
};


class LinkedList {
private:
	Node* head;
	Node* slow;
	Node* fast;
public:
	LinkedList(vector<int> v1) {
		Node* curr = nullptr;
		for (auto it = v1.begin(); it != v1.end(); ++it) {
			Node* tmp = new Node(*it);
			if (!head) {
				head = tmp;
			}
			else {
				curr->next = tmp;
			}
			curr = tmp;
		}
	}


	bool isPallindrome() {
		slow = head;
		fast = head->next;
		bool flag = false;
		stack<int> s1;

		while (fast and fast->next) {
			s1.push(slow->val);
			slow = slow->next;
			fast = fast->next->next;
		}
		while (!s1.empty() and slow) {
			if (flag == false and slow->val == s1.top()) {
				s1.pop();
				
			}
			else if (flag == true){
				if (slow->val != s1.top()) {
					return false;
				}
				else {
					s1.pop();
				}
			}
			flag = true;
			slow = slow->next;
		}
		return true;
	}
};


int main() {
	vector<int> v1 = { 1,2,3,4,3,2};
	LinkedList l1 = LinkedList(v1);
	bool ret_val = l1.isPallindrome();

	cout << ret_val << endl;

}