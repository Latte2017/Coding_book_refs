/*
Users can choose oldest or they can choose cat or dog
	Maintain 3 Qs
		1) Oldest
		2) Cat 
		3) Dog
*/
#include<deque>
#include<string>
#include <iostream>

using namespace std;
class Oldest {
private:
	deque<string> oldest, cat, dog;
public:

	void add(string type, string name) {
		if (type == "cat") {
			cat.push_back(name);
		}
		else {
			dog.push_back(name);
		}
		oldest.push_back(type);
	}

	string popHelper(string s) {
		string ret_val;
		if (s == "cat") {
			ret_val = cat.front();
			cat.pop_front();
		}
		else {
			ret_val = dog.front();
			dog.pop_front();
		}
		return ret_val;
	}

	string select(string selection = "oldest") {
		string ret_val;
		if (selection == "oldest") {
			string s1 = oldest.front();
			oldest.pop_front();
			return popHelper(s1);
		}
		return popHelper(selection);
	}
};

int main() {
	Oldest old;
	old.add("dog", "d1");
	old.add("cat", "c1");
	old.add("dog", "d2");
	old.add("dog", "d3");
	cout << old.select() << endl;
	old.add("dog", "d4");
	old.add("cat", "c2");
	cout << old.select() << endl;
	cout << old.select("cat") << endl;

}