/*
If an element is zero then row and column are zero
	Solution: Mark [r][0] and [0][c] as zeros during the first pass
				Second pass check if beginning of row or column is zero and make zero
*/
#include <vector>
#include<iostream>

using namespace std;

class matrix {
public:
	void makeZero(vector<vector<int>> &input_matrix) {
		for (int r = 0; r < input_matrix.size(); ++r) {
			for (int c = 0; c < input_matrix.size(); ++c) {
				if (input_matrix[r][c] == 0) {
					input_matrix[0][c] = 0;
					input_matrix[r][0] = 0;
				}
			}
		}

		for (int r = 0; r < input_matrix.size(); ++r) {
			for (int c = 0; c < input_matrix.size(); ++c) {
				if (input_matrix[r][0] == 0 or input_matrix[0][c] == 0) {
					input_matrix[r][c] = 0;
				}
			}
		}

	}
};


int main() {
	vector<vector<int>> v1 = { {1,2,3},{4,0,6},{7,8,9} };
	matrix i1 = matrix();
	i1.makeZero(v1);
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[0].size(); ++j) {
			cout << v1[i][j] << "\t";
		}
		cout << endl;
	}
}