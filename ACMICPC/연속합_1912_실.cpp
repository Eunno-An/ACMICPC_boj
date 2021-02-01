
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

int n;
int arr[100001];
int arr_range_sum[100001];
int dp[100001];
// �׽�Ʈ ���̽� �ʱ�ȭ ��
void init()
{

}

int main()
{
	//���� ��ȭ��
	//dp[i] = max(arr[i], arr_range_sum[i], dp[i-1] + arr[i])
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr_range_sum[i] = arr_range_sum[i - 1] + arr[i];
	}
	/*cout << "arr:";
	for (int i = 1; i <= n; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';
	cout << "arr_range_sum:";
	for (int i = 1; i <= n; i++) {
		cout << arr_range_sum[i] << ' ';
	}
	cout << '\n';*/
	dp[1] = arr_range_sum[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = max(max(arr[i], arr_range_sum[i]), dp[i - 1] + arr[i]);
	}
	/*cout << "dp:";
	for (int i = 1; i <= n; i++) {
		cout << dp[i] << ' ';
	}
	cout << '\n';*/
	int max_val = -1000000001;
	for (int i = 1; i <= n; i++) {
		if (dp[i] > max_val) {
			max_val = dp[i];
		}
	}
	cout << max_val << '\n';
	return 0;
}