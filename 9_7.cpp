/*
Paint fill

Given a 2d matrix fill the paint with new color
*/
#include<iostream>
#include<vector>

using namespace std;

class Paint {
private:
	void FillHelper(vector<vector<int>>& input, int x, int y, int oldcolor, int newcolor) {
		if (x <0 or x>= input.size() or y < 0 or y>= input[0].size() or input[x][y] != oldcolor) {
			return;
		}
		if (input[x][y] == oldcolor) {
			input[x][y] = newcolor;
		}
		FillHelper(input, x + 1, y, oldcolor, newcolor);
		FillHelper(input, x - 1, y, oldcolor, newcolor);
		FillHelper(input, x, y-1, oldcolor, newcolor);
		FillHelper(input, x, y+1, oldcolor, newcolor);
		return;
	}
public:
	void fill(vector<vector<int>>& input) {
		FillHelper(input, 0, 0, 1, 2);
		return;
	}
};

int main() {
	vector<vector<int>> input(10, vector<int>(10, 0));

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			input[i][j] = 1;
		}
	}
	input[2][5] = 0;
	input[9][8] = 0;
	Paint p1;
	p1.fill(input);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << input[i][j] << "\t";
		}
		cout << endl;
	}
	return 0;
}