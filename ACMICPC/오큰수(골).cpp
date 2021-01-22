#include<iostream>
#include<stack>
#include<deque>
using namespace std;
int main() {
	int N; // 1 <= N <= 1,000,000
	cin >> N;
	stack<int> inputs, outputs;
	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		inputs.push(input);
	}
	//4  
	//9 5 4 8
	deque<int> result;
	while (!inputs.empty()) {
		int top = inputs.top();
		inputs.pop();
		if (outputs.empty()) {
			outputs.push(top);
			result.push_front(-1);
			continue;
		}
		if (top < outputs.top()) {
			result.push_front(outputs.top());
			outputs.push(top);
		}
		else {
			while (!outputs.empty() && top >= outputs.top() ) {
				outputs.pop();
			}
			if (outputs.size() == 0) {
				result.push_front(-1);
			}
			else {
				result.push_front(outputs.top());
			}
			outputs.push(top);
		}
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}
	cout << '\n';
	return 0;
}