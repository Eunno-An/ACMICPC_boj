
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

int N, S, M;
vector<int> V;
bool dp[110][1010];
int max_val = -1;
// �׽�Ʈ ���̽� �ʱ�ȭ ��
void init()
{
	
	
}
void find_Max(int now_idx, int before_val) {
	if (before_val == -1) {
		return;
	}
	if (now_idx == N) {
		int temp_max_val = -1;
		for (int i = 0; i < 2; i++) {
			if (dp[i][now_idx - 1] != -1) {
				if (temp_max_val < dp[i][now_idx - 1]) {
					temp_max_val = dp[i][now_idx - 1];
				}
			}
		}
		if (max_val < temp_max_val) {
			max_val = temp_max_val;
		}
		return;
	}
	int volume_dif = V[now_idx];
	if (before_val - volume_dif >= 0) {
		dp[0][now_idx] = before_val - volume_dif;
	}
	if (before_val + volume_dif <= M ) {
		dp[1][now_idx] = before_val + volume_dif;
	}
	now_idx++;

	for (int j = 0; j < 2; j++) {
		if (dp[j][now_idx - 1] != -1) {
			find_Max(now_idx, dp[j][now_idx - 1]);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	cin >> N >> S >> M; // ���� ����, ���� ����, M���� ū ��
	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		V.push_back(input);
	}
	/*if (S - V[0] >= 0) {
		dp[0][0] = S - V[0];
	}
	if (S + V[0] <= M) {
		dp[1][0] = S + V[0];
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 2; j++) {
			if (dp[j][i - 1] != -1) {
				find_Max(i, dp[j][i - 1]);
			}
		}
	}*/
	//���� dp �迭�� ��� ��������
	//2 2 2 2 2 2... 2 -> 2 ^100�� ȣ��
	//cout << max_val << '\n';

	if (S + V[0] <= M) dp[0][S + V[0]] = true;
	if (S - V[0] >= 0) dp[0][S - V[0]] = true;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= M; j++) {
			if (dp[i - 1][j]) {
				if (j + V[i] <= M) dp[i][j + V[i]] = true;
				if (j - V[i] >= 0) dp[i][j - V[i]] = true;
			}
		}
	}
	for (int i = M; i >= 0; i--) {
		if (dp[N-1][i]) {
			cout << i << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';
	return 0;
}