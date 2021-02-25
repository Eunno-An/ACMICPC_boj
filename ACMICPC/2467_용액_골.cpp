
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include<iomanip>

using namespace std;

/*
- endl ��� '\n' ����ϱ�
- cin.tie(0) ���
- �׽�Ʈ ���̽� �ִ� ������ �� �������� �ʱ�ȭ �Ű澲��
- (A + B + C) % D = ((A + B) % D + C) % D
- ���ڿ� ��� ������ ���� ���ڿ� �����ؼ� �ڵ忡 �ֱ�
- ��ȣ ��� �����ϱ�
- ���ڿ��� �Լ��� �ѱ� �� const & �� ����ϱ�

- �־��� ��� int �� �ʰ��ϴ���, �迭 �ε��� �ʰ��ϴ��� Ȯ��
- n ���� Ȯ�� (0�� ���), ������� �����Ҽ� Ȯ��, �Ұ����̽� -1 ��� �� Ȯ��
- ū �迭 ���� �� ��������, ���� ���� �� �ʱ�ȭ, �迭 �뷮 max N + 5
*/

#define MOD 1000000007
#define INT_MAX 987654321
#define MAX 100005

typedef long long int ll;
typedef pair<int, int> pii;
ll N;
ll arr[100001];
// �׽�Ʈ ���̽� �ʱ�ȭ ��
void init()
{

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	arr[N] = 5e9 + 7;
	ll ans = 2e9 + 7;
	ll _first, _second;
	for (int i = 0; i < N; i++) {
		if (arr[i] >= 0 && i + 1 < N) {
			ll res = arr[i] + arr[i + 1];
			if (ans > res) {
				ans = res;
				_first = arr[i];
				_second = arr[i + 1];
			}
		}
		else if (arr[i] < 0) {
			int idx = lower_bound(arr + (i + 1), arr + N, -arr[i]) - arr;
			ll res = abs(arr[i] + arr[idx]);
			if (ans > res) {
				ans = res;
				_first = arr[i];
				_second = arr[idx];
			}
			if (idx - 1 > i) {
				res = abs(arr[i] + arr[idx - 1]);
				if (ans > res) {
					ans = res;
					_first = arr[i];
					_second = arr[idx - 1];
				}
			}
		}
	}
	cout << _first << ' ' << _second << '\n';
	//https://seongjuk.tistory.com/entry/BOJ-%EB%B0%B1%EC%A4%80-2467%EB%B2%88-%EC%9A%A9%EC%95%A1
	return 0;
}