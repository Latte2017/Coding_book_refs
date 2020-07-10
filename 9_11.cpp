/*
How many number of ways can an expression be split to get desired result --> 

1 ^ 0 ^ 0 | 1
	|
	+--(1) ^ (0 ^ 0 | 1)
	|  +--(1) ^ ((0 ^ 0) | 1)
	|  +--(1) ^ (0 ^ (0 | 1))
	|
	+--(1 ^ 0) ^ (0 | 1)
	|
	+--(1 ^ 0 ^ 0) | (1)
	   +--((1 ^ 0) ^ 0) | (1)
	   +--(1 ^ (0 ^ 0)) | (1)

	Total Operations 
		xor = numways(left_false*right_false) + numWays(left_false*right_true) + numWays(left_true*right_false) + numWays(left_true*right_true)
		or = numways(left_false*right_false) + numWays(left_false*right_true) + numWays(left_true*right_false) + numWays(left_true*right_true)
		and = numways(left_false*right_false) + numWays(left_false*right_true) + numWays(left_true*right_false) + numWays(left_true*right_true)


	Desired result is true for following operations
		xor = numWays(left_false * right_true) + numWays(left_true * right_false)
		or = numWays(left_false * right_true) + numWays(left_true* right_false) + numWays(left_true*right_true)
		and = numWays(left_true* right_true)

	Desired result is false for following operations
		xor false = Total xor - true reults of xor
		or false = Total or - true reults of or
		and false = Total and - true reults of and
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Splits {
public:

	
	int NumSplits(string expression, bool expected_result) {
		int ltrue, rtrue, lfalse, rfalse;
		if (expression.size() == 1) {
			if (stoi(expression) == expected_result) {
				return 1;
			}
			else {
				return 0;
			}
		}
		int totaltrue = 0;
		int total = 0;
		for (int iter = 1; iter < expression.size(); iter+=2) {
			char c = expression[iter];
			string left = expression.substr(0, iter);
			string right = expression.substr(iter+1, expression.size());
			lfalse = NumSplits(left, false);
			ltrue = NumSplits(left, true);
			rfalse = NumSplits(right, false);
			rtrue = NumSplits(left, true);
			total = lfalse * ltrue + rfalse * rtrue;
			
			if (c == '^') {
				totaltrue = lfalse * rtrue + ltrue * rfalse;
			}
			else if (c == '|') {
				totaltrue = lfalse * rtrue + ltrue * rfalse + ltrue * rtrue;
			}
			else {
				totaltrue = ltrue * rtrue;
			}
		}
		if (expected_result == true) {
			return totaltrue;
		}
		else {
			return total - totaltrue;
		}
	}
};



int main() {
	string input = "1^0|0|1";
	Splits s1;
	int numWays = s1.NumSplits(input, true);
}