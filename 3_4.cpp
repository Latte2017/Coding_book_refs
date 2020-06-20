/*
Tower of Hannoi
Step 1 : Shift first disk from 'A' to 'B'.
Step 2 : Shift second disk from 'A' to 'C'.
Step 3 : Shift first disk from 'B' to 'C'.


Shift 'n-1' disks from 'A' to 'B'.
Shift last disk from 'A' to 'C'.
Shift 'n-1' disks from 'B' to 'C'.

*/

#include <iostream>

using namespace std;

class Hannoi {
public:

	void makeTower(int n, char from_rod, char to_rod, char aux_rod) {
		if (n == 1) {
			cout << "Move from " << from_rod << " to " << to_rod << endl;
			return;
		}

		makeTower(n - 1, from_rod, aux_rod, to_rod);
		cout << "Move disk " << n << " from rod " << from_rod <<
			" to rod " << to_rod << endl;
		makeTower(n - 1, aux_rod, to_rod, from_rod);
	}
};

int main() {
	Hannoi h1;
	h1.makeTower(4, 'A', 'C', 'B');

}