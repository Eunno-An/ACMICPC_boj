#include<iostream>
#include<string>
#include<list>
using namespace std;
int main() {
	int N;
	string command;
	list<int> l;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> command;
		int X;
		if (command == "push_front") {
			cin >> X;
			l.push_front(X);
		}
		else if (command == "push_back") {
			cin >> X;
			l.push_back(X);
		}
		else if (command == "pop_front") {
			if (l.size() == 0) {
				cout << -1 << '\n';
				continue;
			}
			cout << l.front() << '\n';
			l.pop_front();
		}
		else if (command == "pop_back") {
			if (l.size() == 0) {
				cout << -1 << '\n';
				continue;
			}
			cout << l.back() << '\n';
			l.pop_back();
		}
		else if (command == "size") {
			cout << l.size() << '\n';
		}
		else if (command == "empty"){
			if (l.empty()) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (command == "front") {
			if (l.size() == 0) {
				cout << -1 << '\n';
				continue;
			}
			cout << l.front() << '\n';
		}
		else if (command == "back") {
			if (l.size() == 0) {
				cout << -1 << '\n';
				continue;
			}
			cout << l.back() << '\n';
		}
	}
	return 0;
}