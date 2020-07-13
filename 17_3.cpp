/*
Compute the number of zeros in n factorialn1,n2

5! = 5*4*3*2*1

11 10 9 8 7 6 5 4 3 2
*/

#include <algorithm>

using namespace std;
class Factorial {
public:
	int Compute(int num) {
		int zeros = 0;
		while (num > 0) {
			int dem = 5;
			while (num / dem > 0) {
				zeros += num / dem;
				dem *= 5;
			}
			num /= 5;
		}
		return zeros;
	}
};

int main() {
	int num = 19;
	Factorial f1;
	int val = f1.Compute(num);
}