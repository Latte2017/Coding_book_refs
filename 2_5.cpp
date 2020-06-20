/*
Add 2 linked list
*/


#include<list>
#include <iostream>

using namespace std;



class Addition {
public:
	list<int> Add(list<int> l1, list<int> l2) {
		auto it1 = l1.begin();
		auto it2 = l2.begin();
		int carry = 0;
		int sum = 0;
		while (it1 != l1.end() or it2 != l2.end() or carry > 0) {
			if (it1 != l1.end() and it2 != l2.end()) {
				sum = *it1 + *it2 + carry;
				*it1 = int(sum % 10);
				carry = int(sum / 10);
				it1++;
				it2++;
			}
			else if (it2 != l2.end()) {
				sum = *it2 + carry;
				carry = int(sum / 10);
				l1.push_back(int(sum % 10));
				it2++;
			}
			else if (carry > 0){
				if (it1 != l1.end()) {
					sum = *it1 + carry;
					*it1 = int(sum % 10);
					carry = int(sum / 10);
					it1++;
				}
				else {
					l1.push_back(int(carry%10));
					carry = carry/10;
				}

			}
		}
		return l1;
	}
};




int main() {
	list<int> l1 = { 7, 1 };
	list<int> l2 = { 5,9, 9 };
	Addition addnumbers;
	list<int> l3 = addnumbers.Add(l1, l2);
	for (auto it = l3.begin(); it != l3.end(); ++it) {
		cout << *it << "\t";
	}
}