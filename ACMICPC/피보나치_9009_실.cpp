
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

int T;
ll arr[50] = {};
vector<ll> vec_fibo;
// �׽�Ʈ ���̽� �ʱ�ȭ ��
void init()
{
	vec_fibo.clear();
}
void push_fibo(int value, int idx) {
	if (value < arr[idx]) {
		return;
	}
	if (value == 0) {
		return;
	}
	
	vec_fibo.push_back(arr[idx]);
	for (int i = idx-1; i >= 1; i++) {
		push_fibo(value - arr[i], i);
	}
}
ll fibonacci(int idx) {
	if (idx <= 2) {
		return arr[idx] = 1;
	}
	if (arr[idx]) {
		return arr[idx];
	}
	return arr[idx] = fibonacci(idx - 1) + fibonacci(idx - 2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	fibonacci(48);
	while (T--) {
		int n;
		cin >> n;
		int start_idx = 0;
		for (int i = 1; i < 48; i++) {
			if (arr[i] > n) {
				start_idx = i;
				break;
			}
		}
		push_fibo(n, start_idx-1);
		sort(vec_fibo.begin(), vec_fibo.end());
		for (int i = 0; i < vec_fibo.size(); i++) {
			cout << vec_fibo[i] << ' ';
		}
		cout << '\n';
		init();
	}


	return 0;
}