/*
Given a large text file. Given 2 words find the shortest distance between 2 words

geeks for geeks contribute practice

*/



#include <windows.h>
#include<string>
#include<fstream>
#include<set>
#include <random>
#include <iostream>
using namespace std;


int MinDistance(string fileName, string word1, string word2) {
	int max_idx1=0, max_idx2=float('INF');
	int curr_idx1= 0, curr_idx2=float('INF');
	ifstream infile(fileName);
	int l_number = 0;
	if (infile.is_open()) {
		std::string line;
		while (getline(infile, line)) {


			if (line == word1) {
				curr_idx1 = l_number;

				if (abs(curr_idx1 - curr_idx2) < abs(max_idx1 - max_idx2)) {
					max_idx1 = curr_idx1;
				}
			}
			else if (line == word2) {
				curr_idx2 = l_number;

				if (abs(curr_idx1 - curr_idx2) < abs(max_idx1 - max_idx2)) {
					max_idx2 = curr_idx2;
				}
			}
			l_number++;
		}
		return abs(max_idx1 - max_idx2);
	}
	
	return 0;

}







int main() {
	string filename = "words.txt";
	string foldername= "C:\\Users\\kiran.kasichayanula\\source\\repos\\Cracking_the_coding_interview\\";
	int distance = MinDistance(foldername + filename, "2", "6-point");
	cout << distance;

}