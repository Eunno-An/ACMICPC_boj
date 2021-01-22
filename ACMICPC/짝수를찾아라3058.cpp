#include<iostream>
using namespace std;
int main() {
	int testcase;
	int sum, min;
	cin >> testcase;
	
	int input;
	for (int i = 0; i < testcase; i++) {
		sum = 0;
		min = 102;
		for (int j = 0; j < 7; j++) {
			cin >> input;
			if (input % 2 == 0) {
				sum += input;
			}
			if (min > input && input % 2 == 0) {
				min = input;
			}
		}
		cout << sum << ' ' << min << '\n';
	}
	return 0;
}