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
	//deque�� pq���� ó�� ����Ѵ�.
	//�켱���� ���ŵ� �ֵ��� �������� ���ִ°� �ٽ�.
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