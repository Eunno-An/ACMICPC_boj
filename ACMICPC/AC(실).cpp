#include<iostream>
#include<string>
#include<deque>
#include<sstream>
using namespace std;
deque<string> tokenize_getline(const string& data, const char delimiter) {
	deque<string> result;
	string token;
	stringstream ss(data);

	while (getline(ss, token, delimiter)) {
		result.push_back(token);
	}
	return result;
}
int main() {
	int T;
	cin >> T; // 1 <= T <= 100
	for (int i = 0; i < T; i++) {
		string p; // 1 <= p.length <= 100,000
		int n; // 0 <= n <= 100,000
		string numbers; // 1 <= x_i <= 100
		deque<int> arr;
		cin >> p >> n >> numbers;
		if (numbers == "[]") {
			bool f = false;
			for (int j = 0; j < p.size(); j++) {
				if (p[j] == 'D') {
					cout << "error\n";
					f = true;
					break;
				}
			}
			if (f) {
				continue;
			}
			else {
				cout << "[]\n";
				continue;
			}
		}
		deque<string> result = tokenize_getline(numbers, ',');
		/*cout << result.size() << '\n';
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << ' ';
		}*/
		result.front().erase(result.front().begin() + 0);
		result.back().erase(result.back().begin() + result.back().size() - 1);
		for (int j = 0; j < result.size(); j++) {
			arr.push_back(stoi(result[j]));
		}
		bool flag = false; // false: front, true: back
		bool flag2 = false;
		for (int j = 0; j < p.size(); j++) {
			if (p[j] == 'R') {
				flag = !flag;
			}
			else if (p[j] == 'D') {
				if (arr.size() == 0) {
					cout << "error\n";
					flag2 = true;
					break;
				}
				if(!flag){
					arr.pop_front();
				}
				else {
					arr.pop_back();
				}
			}
		}
		if (flag2) {
			continue;
		}
		else if (flag) {
			if (arr.size() == 0) {
				cout << "[]\n";
				continue;
			}
			cout << '[';
			for (int j = arr.size()-1; j >0; j--) {
				cout << arr[j] << ',';
			}
			cout << arr[0] << ']';
		}
		else {
			if (arr.size() == 0) {
				cout << "[]\n";
				continue;
			}
			cout << '[';
			for (int j = 0; j < arr.size()-1; j++) {
				cout << arr[j] << ',';
			}
			cout << arr[arr.size() - 1] << ']';
		}
		cout << '\n';

	}
	return 0;
}