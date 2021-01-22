#include<iostream>
#include<stack>
using namespace std;
int main() {
	int N;
	cin >> N; // 1 <= N <= 500,000
	stack<pair<int, int>> s;
	//2 4 1 2 2 5 1
	pair<int, int> input_stack;
	long long cnt = 0, tmp =0;
	for (int i = 0; i < N; i++) {
		stack<pair<int, int>> t;
		cin >> input_stack.first;
		input_stack.second = 1;
		while (!s.empty()) {
			if (s.top().first <= input_stack.first) {
				cnt += (long long)s.top().second;
				if (s.top().first == input_stack.first)
					input_stack.second += s.top().second;
				s.pop();
			}
			else {
				if (!s.empty()) {
					cnt++;
				}
				break;
			}
		}
		s.push(input_stack);
	}
	cout << cnt << '\n';

	return 0;
}