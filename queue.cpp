/*
Implement a queue
*/

#include<iostream>
#include<vector>

using namespace std;

class que {
private:
	vector<int> q;
public:
	que(vector<int> input) {
		for (auto it = input.begin(); it != input.end(); ++it) {
			q.push_back(*it);
		}
	}

	void appendleft(int x) {
		q.insert(q.begin(), x);
	}

	void appendright(int x) {
		q.push_back(x);
	}

	int popfront() {
		if (!q.empty()) {
			int val = q[0];
			q.erase(q.begin());
			return val;
		}
	}

	int popback() {
		if (!q.empty()) {
			int val = q[q.size() - 1];
			q.pop_back();
			return val;
		}
	}
};