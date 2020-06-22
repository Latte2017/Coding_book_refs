/*
A child is running up the stairs. He can jump 1 step, 2 steps or 3 steps. How many different ways can he jump.
*/

#include<iostream>

using namespace std;

/*
0 1 2 3 
  1 2 
	
      1 + 1 + 1 + 
	0 - 1 - 2 - 3
	0 - 1 - 3
	0 - 2 - 1
	0 - 3 

3 -> 2, 1, 0
     2  1  0 = 3 
*/

class Steps {
public:
	int DifferentWays(int number_of_stairs) {
		int ret_ways = 0;
		if (number_of_stairs == 1) {
			return 1; //1 step
		}
		else if (number_of_stairs == 2) {
			return 2; // 2 steps or 1+1
		}
		else if (number_of_stairs == 3) {
			return 4; // 3 steps or 2+1 or 1+2 or 3 ones
		}
		else if (number_of_stairs <= 0) {
			return 0;
		}

		else {
			ret_ways = DifferentWays(number_of_stairs - 3) + DifferentWays(number_of_stairs - 2) + 
				DifferentWays(number_of_stairs - 1);
		}
		return ret_ways;
	}
};

int main() {
	Steps s1;
	cout << s1.DifferentWays(5) << endl;
}