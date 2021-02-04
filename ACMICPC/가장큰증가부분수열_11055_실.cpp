
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
int dp[1001];
// �׽�Ʈ ���̽� �ʱ�ȭ ��
void init()
{
	for (int i = 1; i <= N; i++) {
		dp[i] = arr[i];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	init();
	for (int i = N; i >= 1; i--) {
		int max_val = dp[i];
		for (int j = i; j <= N; j++) {
			if (arr[i] < arr[j]) {
				if (max_val < dp[j] + dp[i]) {
					max_val = dp[j] + dp[i];
				}
			}
		}
		/*cout << max_val << '\n';*/
		dp[i] = max_val;
	}
	int max_val = 0;
	for (int i = 1; i <= N; i++) {
		if (max_val < dp[i]) {
			max_val = dp[i];
		}
	}
	cout << max_val << '\n';
	return 0;
}