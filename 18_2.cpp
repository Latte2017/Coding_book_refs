/*
Given a deck of cards shuffle so that its perfectly random
*/

#include<vector>
#include<algorithm>
#include <iostream>

using namespace std;

void shuffle(vector<int>& input) {

	for (auto it = 0; it < input.size(); ++it) {
		int rand_num = it + rand() % (input.size() - it);
		cout << "number is " << it << "rand is " << rand_num << endl;
		swap(input[it], input[rand_num]);
		
	}
	return;
}

int main() {
	vector<int> input;

	for (auto it = 1; it < 53; ++it) {
		input.push_back(it);
	}
	shuffle(input);
}