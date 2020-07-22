/*
Write a function to add 2 numbers

Donot use arthametic operations

We can use bit wise and
011
010

*/

class BitSum {
public:
	int Addition(int x, int y) {
		while (y > 1) {
			int sum = x ^ y;
			int carry = (x & y) << 1;
			x = sum;
			y = carry;
		}
		return x;
	}
};


int main() {
	BitSum b1;
	int ret_num = b1.Addition(3, 5);
}




