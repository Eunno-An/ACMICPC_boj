
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
int N;
int arr[1001];
int dp_ascending[1001];
int dp_descending[1001];
int dp_bitonic[1001];
// �׽�Ʈ ���̽� �ʱ�ȭ ��
void init()
{
	for (int i = 1; i <= N; i++) {
		dp_ascending[i] = 1;
		dp_descending[i] = 1;
		dp_bitonic[i] = 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	/*for (int i = 1; i <= 500; i++) {
		cout << i << ' ';
	}
	for (int i = 499; i >= 1; i--) {
		cout << i << ' ';
	}*/
	cin >> N;

	init();
	
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= N; i++) {
		int max_val = dp_ascending[i];
		for (int j = 1; j <= i; j++) {
			if (arr[i] > arr[j]) {
				if (max_val < dp_ascending[j] + 1) {
					max_val = dp_ascending[j] + 1;
				}
			}
		}
		dp_ascending[i] = max_val;
	}
	
	for (int i = N; i >= 1; i--) {
		int max_val = dp_descending[i];
		for (int j = i; j <= N; j++) {
			if (arr[i] > arr[j]) {
				if (max_val < dp_descending[j] + 1) {
					max_val = dp_descending[j] + 1;
				}
			}
		}
		dp_descending[i] = max_val;
	}
	/*
	for (int i = 1; i < N; i++) {
		if (arr[i] != arr[i + 1]) {
			dp_bitonic[i] = dp_ascending[i] + dp_descending[i + 1];
		}
		else {
			dp_bitonic[i] = max(dp_ascending[i], dp_descending[i]);
		}
	}*/
	//dp_bitonic[N] = dp_ascending[N];

	for (int i = 1; i <= N; i++) {
		dp_bitonic[i] = dp_ascending[i] + dp_descending[i] - 1;
	}

	int max_val = 1;
	for (int i = 1; i < N; i++) {
		if (max_val < dp_bitonic[i]) {
			max_val = dp_bitonic[i];
		}
	}
	cout << max_val << '\n';
	return 0;
}
//
//5 1 4 4 2 3 2 1 1 1
//1 5 2 1 4 3 3 3 2 1
//1 1 1 1 1 1 1 1 1 1
