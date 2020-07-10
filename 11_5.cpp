/*
Given a sorted array of string, find the location of given string if there are empty strings in middle

find ball in 
{"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""}


lexicographical_compare Compares 2 strings and returns true if first is smaller than second
*/

#include<vector>
#include<string>
#include<algorithm>
#include <iostream>

using namespace std;

class StringLoc {
public:
	int Find(vector<string>& input_vec, string result) {
		int lo = 0;
		int hi = input_vec.size() - 1;

		while (lo <= hi) {
			int mid = lo + (hi - lo) / 2;
			
			if (input_vec[mid] == result) {
				return mid;
			}
			else if (input_vec[mid].empty()) {
				int left = mid-1;
				while (left >= 0 and input_vec[left].empty()) {
					left--;
				}
				
				if (left >= 0) {
					auto cmp1 = lexicographical_compare(input_vec[left].begin(), input_vec[left].end(), result.begin(), result.end()); 
					if (cmp1) {
						lo = mid + 1;
					}
					else {
						hi = left;
					}
				}
				else{
					lo = mid + 1;
				}
			}
			else if (lexicographical_compare(input_vec[mid].begin(), input_vec[mid].end(), result.begin(), result.end())) {
				lo = mid + 1;
			}
			else {
				hi = mid - 1;
			}

		}

		
	}
};


int main() {
	vector<string> input_vec = { "at", "", "", "", "ball", "", "", "car", "", "", "dad", "", "" };
	StringLoc s1;
	int pos = s1.Find(input_vec, "ball");
	cout << pos << endl;
}
