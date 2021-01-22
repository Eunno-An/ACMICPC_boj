#include<iostream>
#include<deque>
using namespace std;

#define min_value 1000000001
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, L;
	cin >> N >> L;
	deque<pair<int, int>> d;
	pair<int, int> temp;
	int input;
	//deque을 pq느낌 처럼 사용한다.
	//우선순위 제거된 애들은 빨리빨리 빼주는게 핵심.
	for (int i = 0; i < N; i++) {
		cin >> input;
		if (!d.empty() && d.front().second <= i - L) d.pop_front();
		while (d.size() && d.back().first >= input) {
			d.pop_back();
		}
		temp.first = input;
		temp.second = i;
		d.push_back(temp);
		cout << d.front().first << ' ';
	}
	return 0;
}