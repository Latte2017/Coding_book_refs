/*
Robot starts from 0,0 how many ways can he reach x,y
*/

#include<iostream>
#include<unordered_map>
#include <set>
using namespace std;


struct hash_pair {
	template <class T1, class T2>
	size_t operator()(const pair<T1, T2>& p) const
	{
		auto hash1 = hash<T1>{}(p.first);
		auto hash2 = hash<T2>{}(p.second);
		return hash1 ^ hash2;
	}
};

class Robot {
public:
	int NumWays(pair<int, int> start, pair<int, int> target, unordered_map<pair<int,int>, int, hash_pair>memo, set<pair<int, int>> uniq_pairs) {
		int numberOfWays = 0;
		int x = target.first;
		int y = target.second;

		std::unordered_map<pair<int,int>, int>::const_iterator got = memo.find(target);

		if (got != memo.end()) {
			return got->second;
		}

		if (x < 0 or y < 0) {
			return 0;
		}

		std::set<pair<int, int>>::const_iterator it = uniq_pairs.find(target);
		if (x == 0 and y == 0 and it == uniq_pairs.end()) {
			pair<int, int> tmp = make_pair(x, y);
			uniq_pairs.insert(tmp);
			return 1;

		}

		int num_left = NumWays(start, make_pair(x - 1, y), memo, uniq_pairs);
		int num_up = NumWays(start, make_pair(x, y - 1), memo, uniq_pairs);

		memo[target] = num_left + num_up;
		numberOfWays += num_left + num_up;

		return numberOfWays;
	}
};

int main() {
	Robot r1;
	unordered_map<pair<int, int>, int, hash_pair>memo;
	set<pair<int, int>> uniq_pairs;
	int num = r1.NumWays(make_pair(0, 0), make_pair(2, 2), memo, uniq_pairs);
	cout << num << endl;

}