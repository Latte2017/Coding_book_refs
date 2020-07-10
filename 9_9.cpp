/*
Print all the ways 8 queens donot interct in row, column or diagnol
*/

#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Queens {
private:
	bool CheckViolation(vector<int> input, int row) {
		int row1 = row;
		int col1 = input[row];
		for (int row2 = 0; row2 < row1; row2++) {
			int col2 = input[row2];
			//Check if queen in same column Violation
			if (col1 == col2) {
				return true;
			}
			//Check diagnol
			int colDistance = abs(col2 - col1);
			int rowDistance = row1 - row2;
			if (colDistance == rowDistance) {
				return true;
			}
		}
		return false;
	}

	void ArrangeHelper(int num, vector<int>& recur_vec, set<vector<int>>& ret_vec, int boardsize) {
		for (int i = 0; i < boardsize; i++) {
			recur_vec[num] = i;
			if (recur_vec[0] == 1) {
				cout << "i is " << i << endl;
			}
			if (!CheckViolation(recur_vec, num)) {
				if (num == recur_vec.size() - 1) {
					ret_vec.insert(recur_vec);
				}
				else {
					ArrangeHelper(num + 1, recur_vec, ret_vec, boardsize);
				}

			}
			recur_vec[num] = -1;
		}
	}
public:
	set<vector<int>> arrangment(int boardsize) {
		vector<int> recur_vec(boardsize,-1);
		set<vector<int>> return_vec;
		ArrangeHelper(0, recur_vec, return_vec, boardsize);
		return return_vec;
	}
};


int main() {
	Queens q1;
	set<vector<int>> ret_vec = q1.arrangment(4);

	for (auto it = ret_vec.begin(); it != ret_vec.end(); ++it) {
		for (auto ix = (*it).begin(); ix != (*it).end(); ++ix) {
			cout << *ix << '\t';
		}
		cout << endl;
	}
}