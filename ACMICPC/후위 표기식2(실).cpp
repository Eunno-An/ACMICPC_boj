#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<stdlib.h>
using namespace std;
int main() {
	int N;
	string input;
	vector<int> numbers;
	stack<double> result;
	cin >> N >> input;
	numbers.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> numbers[i];
	}
	double a = 0, b = 0;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '+') {
			b = result.top();
			result.pop();
			a = result.top();
			result.pop();
			result.push((double)a + b);
		}
		else if (input[i] == '-') {
			b = result.top();
			result.pop();
			a = result.top();
			result.pop();
			result.push((double)a - b);
		}
		else if (input[i] == '*') {
			b = result.top();
			result.pop();
			a = result.top();
			result.pop();
			result.push((double)a * b);
		}
		else if (input[i] == '/') {
			b = result.top();
			result.pop();
			a = result.top();
			result.pop();
			result.push(a / b);
		}
		else {
			result.push(numbers[int(input[i]) - 65]);
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << result.top() << '\n';
	return 0;
}