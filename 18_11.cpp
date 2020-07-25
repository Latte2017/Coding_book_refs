/*
Image you have a square matrix where each pixel is black or white.

Design an algorithm to find the max subsquare where all four borders are filled with black pixles

{'X', 'O', 'X', 'X', 'X', 'X'},
{'X', 'O', 'X', 'X', 'O', 'X'},
{'X', 'X', 'X', 'O', 'O', 'X'},
{'X', 'X', 'X', 'X', 'X', 'X'},
{'X', 'X', 'X', 'O', 'X', 'O'}


The subsquare starting with (0,2), (0,5)
                            (3,2), (3,5)

Output: 4

*/

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;




int findSubSquare(const vector<vector<int>> mat) {
	vector<vector<int>> vert(mat.size(), vector<int> (mat.size(),0)), horz(mat.size(), vector<int>(mat.size(), 0));
	int max_size = 0;
	int curr_size = 0;
	for (auto ix = 0; ix < mat.size(); ++ix) {
		for (auto iy = 0; iy < mat.size(); ++iy) {
			if (mat[ix][iy] == 'X') {
				vert[ix][iy] = (ix==0)? 1:vert[ix - 1][iy] + 1;
				horz[ix][iy] = (iy==0)? 1:horz[ix][iy-1] + 1;
			}
		}
	}

	cout << "vertical" << endl;
	for (auto ix = 0; ix < mat.size(); ++ix) {
		for (auto iy = 0; iy < mat.size(); ++iy) {
			cout << vert[ix][iy] << "\t";
			
		}
		cout << '\n';
	}

	cout << "horizontal" << endl;
	for (auto ix = 0; ix < mat.size(); ++ix) {
		for (auto iy = 0; iy < mat.size(); ++iy) {
			
			cout << horz[ix][iy] << '\t';
		}
		cout << '\n';
	}

	for (auto ix = 0; ix < mat.size(); ++ix) {
		for (auto iy = 0; iy < mat.size(); ++iy) {
			if (mat[ix][iy] == 'X') {
				vert[ix][iy] = (ix == 0) ? 1 : vert[ix - 1][iy] + 1;
				horz[ix][iy] = (iy == 0) ? 1 : vert[ix][iy - 1] + 1;
			}
		}
	}

	cout << '\n';
	cout << '\n';
	//We will start from bottom right

	for (int ix = mat.size() - 1; ix >= 1; ix--) {
		for (int iy = mat.size() - 1; iy >= 1; iy--) {

			curr_size = min(vert[ix][iy], horz[ix][iy]);
			cout << ix << '\t'  << iy << '\t' << vert[ix][iy] << "\t" << horz[ix][iy] << endl;
			while (curr_size > max_size)
			{
				if (vert[ix][iy - curr_size + 1] >= curr_size &&
					horz[ix - curr_size + 1][iy] >= curr_size)
				{
					max_size = curr_size;
				}
				curr_size--;
			}



			/*
			curr_size = min(vert[ix][iy], horz[ix][iy]);
			while (curr_size > max_size) {
				//From the right bottom check left bottom and top right are the same size or greater
				if (horz[ix - curr_size + 1][iy] >= curr_size && vert[ix][iy - curr_size + 1] >= curr_size) {
					max_size = curr_size;
				}
				curr_size--;
			}
			*/
		}
	}
	return max_size;

}

// Driver program to test above function 
int main()
{
	
	vector<vector<int>> mat =
					{ {'X', 'O', 'X', 'X', 'X', 'X'},
					{'X', 'O', 'X', 'X', 'O', 'X'},
					{'X', 'X', 'X', 'O', 'O', 'X'},
					{'O', 'X', 'X', 'X', 'X', 'X'},
					{'X', 'X', 'X', 'O', 'X', 'O'},
					{'O', 'O', 'X', 'O', 'O', 'O'},
	};
	cout << findSubSquare(mat);
	return 0;
}
