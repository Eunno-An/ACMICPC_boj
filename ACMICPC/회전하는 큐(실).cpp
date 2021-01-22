#include<deque>
#include<iostream>
using namespace std;
int main() {
	deque<int> d;
	int N, M;
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		d.push_back(i + 1);
	}
	int input;
	int count = 0;
	for (int i = 0; i < M; i++) {
		cin >> input;
		if (d[0] == input) {
			d.pop_front();
			continue;
		}
		for (int j = 0; j < d.size(); j++) {
			if (input == d[j]) {
				if (j < d.size() - j) {
					count += j;
					for (int k = 0; k < j; k++) {
						int temp = d.front();
						d.pop_front();
						d.push_back(temp);
					}
					d.pop_front();
				}
				else {
					count += d.size() - j;
					for (int k = 0; k < d.size()-j; k++) {
						int temp = d.back();
						d.pop_back();
						d.push_front(temp);
					}
					d.pop_front();
				}
			}
		}
	}
	cout << count << '\n';
}