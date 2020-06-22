/*
Given a number print the next smallest and next largest number with same number of ones as the given number

for example:
	13948 is                    1 1 0 1 1 0 0 1 1 1 1 1 0 0 ->> 9 One's
	next largest is             1 1 0 1 1 0 1 0 0 0 1 1 1 1  --> flip the first zero after a series of ones. 9 One's
	next smallest is            1 1 0 1 1 0 0 1 1 1 1 0 1 0  --> flip the last one to zero and last zero to one 9 One's

*/

#include<iostream>
#include <tuple>

using namespace std;

class nextNumbers {
private:
	int NextLargest(int number) {
		bool flag = false;
		int mask = 1;
		int runner = number;
		int numOnes = 0;
		while (true) {
			if (flag == true and (runner & mask) == 0) {
				break;
			}
			if ((runner & mask) != 0) {
				numOnes += 1;
				flag = true;
			}
			
			mask = mask << 1;
		}
		
	}

	int NextSmallest(int number) {

	}
public:
	std::tuple<int, int> FindNearest(int number) {
		
	}

	

};

int main() {
	int num = 32;
	nextNumbers n1;
	n1.FindNearest(num);
}