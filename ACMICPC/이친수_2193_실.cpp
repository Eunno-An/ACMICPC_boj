
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
int count_twchin = 0;
int dp[2][91] = {};
ll fibo[91] = {};
// �׽�Ʈ ���̽� �ʱ�ȭ ��
void init()
{

}
ll fibonacci(int number) {
	if (number == 1) {
		return fibo[number] = 1;
	}
	if (number == 2) {
		return fibo[number] = 1;
	}
	if (fibo[number]) {
		return fibo[number];
	}
	return fibo[number] = fibonacci(number - 1) + fibonacci(number - 2);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int arr[91] = {};
	init();
	cin >> N;
	if (N == 1 || N == 2) {
		cout << 1 << '\n';
		return 0;
	}
	cout << fibonacci(N) << '\n';
	//��Ģ�� �׳� �Ǻ���ġ��.



	//dp�迭�� �ǹ�
	//dp[0][i]�� i��° �ڸ����� 0�̳� 1�̳ĸ� �ǹ�
	//dp[1][1] = 1;
	//dp[0][2] = 1;
	//for (int i = 3; i <= N; i++) {//dp[0][3]�� dp[1][3]�� ���̽��� ����. dp [0][3] = do[0][2], dp[1][3] = dp[0][2]+1
	//	if (dp[0][i - 1] != 0) {
	//		dp[0][i] = dp[0][i-1];
	//		dp[1][i] = dp[0][i-1];
	//	}
	//	if (dp[1][i - 1] != 0) { // i-1�� 1 �� ��
	//		dp[0][i] += 1;
	//	}
	//}
	//cout << dp[0][N] + dp[1][N] << '\n';
	//dp[0]: 0 1 1 1
	//dp[1]: 1 0 1 1

	return 0;
}