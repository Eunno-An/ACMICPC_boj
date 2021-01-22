#include<iostream>
#include<stack>
#include<string>
using namespace std;
int calculatePriority(char c) {
	if (c == '+' || c == '-') {
		return 2;
	}
	else if (c == '*' || c == '/') {
		return 1;
	}
	else if(c == '(' || c == ')'){
		return 0;
	}
	return -1;
}
int main() {
	string input;
	stack<char> s1;
	string output="";
	int level = 0;
	cin >> input;
	for (int i = 0; i < input.size(); i++) {
		int prior = calculatePriority(input[i]);
		if (prior == -1) {
			output.push_back(input[i]);
			continue;
		}
		if (s1.empty()) {
			s1.push(input[i]);
			continue;
		}
		if (input[i] == ')') {
			while (s1.top() != '(') {
				output.push_back(s1.top());
				s1.pop();
			}
			s1.pop();
			continue;
		}
		else {
			while (!s1.empty() && calculatePriority(s1.top()) <= prior) {
				if (s1.top() == '(') {
					break;
				}
				output.push_back(s1.top());
				s1.pop();
			}
			s1.push(input[i]);
		}
	}
	int size_remain = s1.size();
	for (int i = 0; i < size_remain; i++) {
		output.push_back(s1.top());
		s1.pop();
	}
	cout << output << '\n';
	return 0;
}