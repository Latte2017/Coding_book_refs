/*
two 32 bit numbers (M,N) and 2 bit positions(i,j) fit M into N
N 10000000000
M 10011
i =2 and j = 6 
N 10001001100

Solution:
	Clear the bit in M from i to j
	Shift M by i
	Or M and N
*/

#include<iostream>
#include <bitset>
using namespace std;

class Concantanate {
private:
	int num1;
	int num2;
	int i, j;

public:
	Concantanate(int num1, int num2, int i, int j) {
		this->num1 = num1;
		this->num2 = num2;
		this->i = i;
		this->j = j;
	}

	bitset<32> Append() {
		//Clear bits from i to j
		int mask = CreateMask();
		num1 = num1 & mask;
		//Shift num2 by i
		num2 = (num2 << i);
		//or num1 and num2;
		return (num1 | num2);
	}

	int CreateMask() {
		//Create a mask for num1 from i to j
		//Clear all bits from j through 0
		int mask1 = ~0;
		mask1 = mask1 << (j+1);
		cout << "Mask1 is " << bitset<32>(mask1) << endl;
		int mask2;
		mask2 = (1 << i) - 1;
		cout << "Mask2 is " << bitset<32>(mask2) << endl;
		mask1 = mask1 | mask2;
		return mask1;
	}
};

int main() {
	int num1 = pow(2,10);
	int num2 = 19;
	Concantanate c1 (num1, num2, 2,6);
	bitset<32> ret_num = c1.Append();
	cout << ret_num.to_ulong() << endl;
	return 0;
}
