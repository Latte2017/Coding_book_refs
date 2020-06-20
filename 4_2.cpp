/*
Given a directed graph find the route exists. Initial question was does a route exists
*/

#include<vector>
#include<set>
#include<queue>
#include <iostream>
using namespace std;

class Node {
public:
	int val;
	vector<Node*>  neighbours;
	Node(int x) {
		val = x;
	}
};


class Graph {
private:
	Node* root;
	set<Node*> listOfNodes;
	vector<Node*> visited;
public:
	Graph(Node* input_node) {
		root = input_node;
		listOfNodes.insert(root);
	}

	void addNeighbour(Node* head, vector<Node*> node_neighbours) {
		if (listOfNodes.find(head) == listOfNodes.end()) {
			listOfNodes.insert(head);
		}

		for (auto it = node_neighbours.begin(); it != node_neighbours.end(); ++it) {
			listOfNodes.insert(*it);
			head->neighbours.push_back(*it);
		}
	}

	//BFS
	vector<Node*> isRoute(Node* source, Node* destination) {
		if (listOfNodes.find(destination) == listOfNodes.end() or listOfNodes.find(source) == listOfNodes.end()) {
			return {};
		}

		queue<pair<Node*, vector<Node*>>> que;
		vector<Node*> path;
		path.push_back(source);
		que.push({ source, path });

		while (!que.empty()) {
			auto curr_pair = que.front();
			que.pop();
			visited.push_back(curr_pair.first);


			for (auto it = (curr_pair.first)->neighbours.begin(); it != (curr_pair.first)->neighbours.end(); ++it) {
				curr_pair.second.push_back(*it);
				if (*it == destination) {
					return (curr_pair.second);
				}
				if (find(visited.begin(), visited.end(),*it) == visited.end()) {
					
					que.push({*it, curr_pair.second});
				}
				curr_pair.second.pop_back();
			}
		}
		return {};
	}
};


int main() {
	Node* root = new Node(10);
	Node* n1 = new Node(20);
	Node* n2 = new Node(30);
	Node* n3 = new Node(40);
	Node* n4 = new Node(50);
	Node* n5 = new Node(60);
	Node* n6 = new Node(70);
	Node* n7 = new Node(80);
	Node* n8 = new Node(90);
	Node* n9 = new Node(100);

	Graph* g1 = new Graph(root);
	vector<Node*> neighbours;
	neighbours.push_back(n1);
	neighbours.push_back(n2);
	g1->addNeighbour(root, neighbours);

	neighbours.clear();
	neighbours.push_back(n4);
	g1->addNeighbour(n2, neighbours);

	neighbours.clear();
	neighbours.push_back(n3);
	g1->addNeighbour(n1, neighbours);

	neighbours.clear();
	neighbours.push_back(n5);
	g1->addNeighbour(n4, neighbours);

	neighbours.clear();
	neighbours.push_back(n8);
	g1->addNeighbour(n5, neighbours);

	neighbours.clear();
	neighbours.push_back(n6);
	g1->addNeighbour(n3, neighbours);

	neighbours.clear();
	neighbours.push_back(n7);
	g1->addNeighbour(n6, neighbours);

	neighbours.clear();
	neighbours.push_back(n8);
	g1->addNeighbour(n7, neighbours);

	vector<Node*> ret_val = g1->isRoute(root, n8);
	for (auto it = ret_val.begin(); it != ret_val.end(); ++it) {
		cout << (*it)->val << "\t";
	}
	


}