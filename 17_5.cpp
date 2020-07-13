/*
Given a String which has 4 colors Y,R, G, B and a guess YRRR return number of hits and pseudo hits

Hit if Correct color is guessed in correct slot
Pseudo hit if color is present in answer but in a different slot

EXample: Correct YRBG, guess RRGB hits--> 3 and pseudo hits --> 0

A hit cannt be pseudo hit

*/
#include<unordered_map>
#include<string>
#include<set>
using namespace std;

class Game {
public:
	pair<int, int> Match(string expected, string actual) {
		pair<int, int> ret_pair;
		int hits = 0, pseudo = 0;
		unordered_map<char, set<int>> map1;

		if (expected.empty() or actual.empty()) {
			return make_pair(0, 0);
		}
		for (int i = 0; i < expected.size(); ++i) {
			map1[expected[i]].insert(i);
		}

		for (int i = 0; i < actual.size(); ++i) {
			auto it = map1.find(actual[i]);
			if (it != map1.end()) {
				if ((*it).second.find(i) != (*it).second.end()) {
					hits++;
				}
				else {
					pseudo++;
				}
			}
		}
		return make_pair(hits, pseudo);
	}
};


int main() {
	Game g1;
	string actual = "YRGB", expected = "YYGG";
	pair<int, int> ret_val = g1.Match(actual, expected);
	
}