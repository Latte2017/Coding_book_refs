/*
Rotate the image by 90 degree to right
	Solution: Transpose and reverse
	Solution2: First reverse rows and then swap from row+1 until end

*/
#include<vector>
#include <iostream>

using namespace std;

class Image {
public:
	void rotate(vector<vector<int>> &input) {
		for (unsigned int x = 0; x < input.size(); ++x) {
			for (unsigned int y = 0; y < x; ++y) {
				swap(input[x][y], input[y][x]);
			}
		}
		for (unsigned int i = 0; i < input.size(); ++i) {
			reverse(input[i].begin(), input[i].end());
		}
		return;
	}
	
	void rotate2(vector<vector<int>>& input) {
		reverse(input.begin(), input.end());

		for (unsigned int r = 0; r < input.size(); ++r) {
			for (unsigned int c = r + 1; c < input.size(); ++c) {
				swap(input[r][c], input[c][r]);
			}
		}

	}
	
};

int main() {
	vector<vector<int>> v1, v2 = { {1,2,3},{4,5,6},{7,8,9} };
	Image i1 = Image();
	i1.rotate(v1);
	i1.rotate2(v2);
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[0].size(); ++j) {
			if (v1[i][j] != v2[i][j]){
				cout << v1[i][j] << "\t";
			}
		}
		cout << endl;
	}
}