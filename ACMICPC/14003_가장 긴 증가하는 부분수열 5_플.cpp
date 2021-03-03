
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
ll arr[1000001];
ll dp[1000001];
int idx_arr[1000001];
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
	dp[0] = arr[0];
	
	ll idx = 0;
	for (int i = 1; i < N; i++) {
		if (dp[idx] < arr[i]) {
			dp[++idx] = arr[i];
			idx_arr[i] = idx;
		}
		else {
			ll idx1 = lower_bound(dp, dp + idx, arr[i]) - dp;
			dp[idx1] = arr[i];
			idx_arr[i] = idx1;
		}

	}
	//LIS ���� ���
	int len_lis = idx + 1;
	cout << len_lis << '\n';
	
	vector<int> result;
	for (int i = N - 1; i >= 0; i--) {
		if (idx_arr[i] == len_lis - 1) {
			len_lis--;
			result.push_back(arr[i]);
		}
	}
	for (int i = result.size() - 1; i >= 0; i--) {
		cout << result[i] << ' ';
	}
	cout << '\n';
	
	return 0;
}