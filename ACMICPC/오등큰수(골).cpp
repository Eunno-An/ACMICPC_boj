#include<iostream>
#include<stack>
#include<map>
#include<deque>
#include<string>
#include<vector>
using namespace std;

vector<int> v(1000000);
vector<int> s;
int main() {
	int N;
	cin >> N;
	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		s.push_back(input);
		v[input - 1]++;
	}
	vector<pair<int, int>> p;
	pair<int, int> input_p;
	for (int i = 0; i < N; i++) {
		input_p.first = s[i];
		input_p.second = v[s[i]-1];
		p.push_back(input_p);
	}
	
	stack<pair<int, int>> stack_s;
	deque<int> d;
	while (!p.empty()) {
		pair<int, int> top = p.back();
		p.pop_back();
		if (stack_s.empty()) {
			stack_s.push(top);
			d.push_front(-1);
			continue;
		}
		if (top.second < stack_s.top().second) {
			d.push_front(stack_s.top().first);
			stack_s.push(top);
		}
		else {
			while (!stack_s.empty() && top.second >= stack_s.top().second) {
				stack_s.pop();
			}
			if (stack_s.size() == 0) {
				d.push_front(-1);
			}
			else {
				d.push_front(stack_s.top().first);
			}
			stack_s.push(top);
		}

	}
	for (int i = 0; i < d.size(); i++) {
		cout << d[i] << ' ';
	}
	cout << '\n';
	return 0;
}