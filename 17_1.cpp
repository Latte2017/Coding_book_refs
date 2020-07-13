/*
Swap a number in place

Given 2 numbers swap 2 numbers without temp
*/

#include<tuple>
#include <iostream>

using namespace std;

class Swap {
public:
	pair<int, int> Exchange(int& a, int& b) {
		//Use XOR. XOR with the same number is zero. 
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
		return make_pair(a, b);
	}
};


int main() {
	Swap s1;
	int a = 10;
	int b = 5;
	s1.Exchange(a, b);

	cout << "a is " << a << " b is " << b << endl;
}
