
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
int dp[1001][11];
ll count = 0;
// �׽�Ʈ ���̽� �ʱ�ȭ ��
void init()
{

}
/*
* dp[n][i]
* dp[n][10] = ���̰� n�� ������ ���� ���ڸ��� i�� �� 1���� i������ ������ ���� ���� ��
* dp[1][10] = 1 2 3 4 5 6 7 8 9 10 ( 0 ~ 9 ����)
* dp[2][10] = 00 ~ 09(���ڸ� 0), 11~19(���ڸ� 1), ... 99(���ڸ� 9)
*			= dp[1][10],dp[1][9] +dp[2][1], dp[1][8] + dp[2][2], ... ,dp[1][1] + dp[2][9]
* dp[3][10] = dp[2][10], dp[2][9] + dp[3][0], ...
*/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	cin >> N;
	
	for (int i = 1; i <= 10; i++) {
		dp[0][i] = 1;
		dp[1][i] = i;
	}
	for (int i = 2; i <= N; i++) {
		dp[i][1] = 1;
		for (int j = 2; j <= 10; j++) {
			dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % 10007;
		}
	}
	cout << dp[N][10] << '\n';
	return 0;
}