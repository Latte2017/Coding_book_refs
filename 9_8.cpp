/*
Represent dollor amount in terms of multiples of quarter, dime, nickhel, cent
Write code to give number of combinations
*/

#include<iostream>
#include<vector>
#include<string>
#include<set>

using namespace std;

class Dollor {
	vector<int> denominations = { 25,10,5,1 };
private:
	int Recur(int amount, vector<int>::iterator iter) {
		int ways = 0;
		if (*iter == 1) {
			return 1;
		}
		if (iter == denominations.end()) {
			return 0;
		}
		for (int num_coins = 0; num_coins * (*iter) <= amount; num_coins++) {
			amount -= num_coins * (*iter);
			ways += Recur(amount, iter+1);
		}
		return ways;
	}
public:
	int represent(int amount) {
		return Recur(amount, denominations.begin());
	}
};

int main() {
	int amount = 25;
	Dollor d1;
	int numways = d1.represent(amount);

	cout << "Number of ways " << numways << endl;
}