#include<iostream>
#include<list>
#include<vector>
using namespace std;
class Node {
public:
	int value;
	Node* tail;
	Node* head;
	Node() {
		value = 0;
		tail = NULL;
		head = NULL;
	}
	Node(int val) {
		this->value = val;
	}
};
int main() {
	int N, K;
	vector<Node*> v;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		Node* newNode = new Node(i + 1);
		v.push_back(newNode);
	}
	for (int i = 1; i < N; i++) {
		v[i - 1]->tail = v[i];
		v[i]->head = v[i - 1];
	}
	v[N - 1]->tail = v[0];
	v[0]->head = v[N - 1];
	vector<int> v1;

	Node* startNode = v[K - 1];
	while (N--) {
		v1.push_back(startNode->value);
		startNode->head->tail = startNode->tail;
		startNode->tail->head = startNode->head;
		for (int i = 0; i < K; i++) {
			startNode = startNode->tail;
		}
	}
	cout << "<";
	for (int i = 0; i < v1.size(); i++) {
		if (i != v1.size() - 1) {
			cout << v1[i] << ", ";
		}
		else {
			cout << v1[i] << ">\n";
		}
	}
	return 0;
}