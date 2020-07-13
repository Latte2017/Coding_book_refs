/*
Check if someone has won the tic tac toe game.

Its played on NXN grid


X O O
O X O
O O X

*/

#include<vector>

using namespace std;

class CheckTicTacToe {
public:
	bool IsValid(vector<vector<char>>& input_vec) {
		

		int win_sum = 0;
		for (auto i = 0; i < input_vec.size(); ++i) {
			win_sum = 0;
			for (auto j = 0; j < input_vec.size(); ++j) {
				if (input_vec[i][j] == 'X') {
					win_sum += 1;
				}
				else if (input_vec[i][j] == 'O') {
					win_sum -= 1;
				}
				else {
					break;
				}
			}
			if (abs(win_sum) == input_vec.size()) {
				return true;
			}
		}

		win_sum = 0;
		for (auto i = 0; i < input_vec.size(); ++i) {
			win_sum = 0;
			for (auto j = 0; j < input_vec.size(); ++j) {
				if (input_vec[j][i] == 'X') {
					win_sum += 1;
				}
				else if (input_vec[j][i] == 'O') {
					win_sum -= 1;
				}
				else {
					break;
				}
			}
			if (abs(win_sum) == input_vec.size()) {
				return true;
			}
			
			if (abs(win_sum) == input_vec.size()) {
				return true;
			}
		}

		win_sum = 0;
		for (auto i = 0; i < input_vec.size(); ++i) {
			for (auto j = 0; j < input_vec.size(); ++j) {
				if (i == j) {
					if (input_vec[i][j] == 'X') {
						win_sum += 1;
					}
					else if (input_vec[i][j] == 'O') {
						win_sum -= 1;
					}
					else {
						break;
					}
				}
			}	
		}
		if (abs(win_sum) == input_vec.size()) {
			return true;
		}

		//reverse diag
		win_sum = 0;
		for (auto i = 0; i < input_vec.size(); ++i) {
			for (auto j = 0; j < input_vec.size(); ++j) {
				if (i+j == input_vec.size()-1) {
					if (input_vec[i][j] == 'X') {
						win_sum += 1;
					}
					else if (input_vec[i][j] == 'O') {
						win_sum -= 1;
					}
					else {
						break;
					}
				}
			}
		}
		if (abs(win_sum) == input_vec.size()) {
			return true;
		}

		return false;

	}
};

int main() {
	vector<vector<char>> input_vec = {
		{' ','X','X'},
		{'X', 'X','O'},
		{'O','O','X'}
	};
	CheckTicTacToe Check;
	bool ret_val = Check.IsValid(input_vec);
}