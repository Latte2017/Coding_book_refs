/*
Design a call center where you have 3 levels
1) Responder
2) Manager
3) Director

A call must be directed to respondant who is free. He can escalate to manager who can escalate to director

Dispatch call must be answered by first available responder or if the responder is not available manager and if 
manager is not availabe then director
*/

#include<string>
#include<deque>
#include <iostream>
#include<Windows.h>
#include<vector>
#include<thread>
using namespace std;

class call {
private:
	int caller_id = 0;
	int rank = 0;
	bool call_completed = false;
public:

	call(int id) {
		this->caller_id = id;
	}

	int GetCallerID() {
		return this->caller_id;
	}

	void IncreaseRank() {
		this->rank++;
	}

	void ResetRank() {
		this->rank = 0;
	}

	int GetRank() {
		return rank;
	}

	void CallCompleted() {
		this->call_completed = true;
	}

	bool IsCompleted() {
		return this->call_completed;
	}
};


class Employee {
private:
	int id;
public:

	Employee() {};

	Employee(int id) {
		this->id = id;
	}

	virtual void answer(call* caller) {
		
		srand(0);
		bool val = rand() % 2;
		
		if (val) {
			cout << "Issue resloved" << endl;
			caller->CallCompleted();
		}
		else {
			caller->IncreaseRank();
		}
		return;
	}
	
};





class Responder :public Employee {
public:

	void answer(call* caller){
		Employee::answer(caller);
	}

	~Responder() {
		
	}
};

class Manager : public Employee {
public:

	void answer(call* caller) {
		Employee::answer(caller);
	}
};

class Director : public Employee {

public:
	
	void answer(call* caller) {
		
		Employee::answer(caller);
		if (!caller->IsCompleted()) {
			caller->CallCompleted();
		}	
	}
};

class callManager {
private:
	deque<call*> que;
	vector<Director*> directors;
	vector<Manager*> managers;
	vector<Responder*> responders;
	void AddCall(call* caller) {
		if (!responders.empty()){
			que.push_back(caller);
		}
		else if (!managers.empty()) {
			caller->IncreaseRank();
			que.push_back(caller);
		}
		else if (!directors.empty()) {
			caller->IncreaseRank();
			que.push_back(caller);
		}
		else {
			caller->ResetRank();
			que.push_back(caller);
		}
			
	}

public:
	callManager(int num_directors, int num_managers, int num_responders) {
		for (auto it = 0; it < num_responders; ++it) {
			responders.push_back(new Responder());
		}
		for (auto it = 0; it < num_managers; ++it) {
			managers.push_back(new Manager());
		}
		for (auto it = 0; it < num_directors; ++it) {
			directors.push_back(new Director());
		}

	}


	bool DispatchCall(call* caller) {
		AddCall(caller);
		
		while (!caller->IsCompleted() and caller->GetRank() < 3) {
			if (caller->GetRank() < 1) {
				Responder* level1 = responders.front();
				level1->answer(caller);
				if (!caller->IsCompleted()) {
					que.push_front(caller); //Push to the front of line
				}
				responders.push_back(level1);
			}
			else if (caller->GetRank() < 2) {
				Manager* level2 = managers.front();
				level2->answer(caller);
				if (!caller->IsCompleted()) {
					que.push_front(caller); //Push to the front of line
				}
				managers.push_back(level2);
			}
			else {
				Director* level3 = directors.front();
				level3->answer(caller);
				if (!caller->IsCompleted()) {
					que.push_front(caller); //Push to the front of line
				}
				directors.push_back(level3);
			}
		}
		if (!caller->IsCompleted()) {
			return false;
		}
		return true;
	}
};


int main() {
	callManager m1(1,1,1);
	call c1(1), c2(2), c3(3), c4(4);
	m1.DispatchCall(&c1);
	m1.DispatchCall(&c2);
	m1.DispatchCall(&c3);
	m1.DispatchCall(&c4);

}