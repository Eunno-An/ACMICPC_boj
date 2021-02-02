
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
int n;
int arr[3][100001];
int dp[3][100001];
// �׽�Ʈ ���̽� �ʱ�ȭ ��
void init()
{
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = 0;
			dp[i][j] = 0;
		}
	}
}

//�� �� �������� ��(1, j),
//
//1. ������ �Ʒ� ������ �ϳ��� ���°�� : arr[2][j + 1]
//2. ���� ���� ���, �� ���� ��츦 �� :
//2 - 1 : arr[2][j + 1]�� arr[1][j + 2]�� ���� : �� 2 ���̽��� �ݺ���.
//2 - 2 : arr[2][j + 2]�� ���� : ���� 1���� �Ʒ� 1���� ���ϴ� ���
//
//
//�� �� �������� ��(2, j),
//1. ������ �� ������ �ϳ��� ���°�� : arr[1][j + 1]
//2. ���� ���� ���, �� ���� ��츦 �� :
//2 - 1 : arr[1][j + 1]�� arr[2][j + 2]�� ���� : �� 2���̽��� �ݺ���.
//2 - 2 : arr[1][j + 1]�� ���� : ���� 1���� �Ʒ� 1���� ���ϴ� ���

//50 10 100 20 40
//30 50 70 10 60
//
//50 ���� -> 50�� 100���� -> 60����
//
//7
//10 30 10 50 100 20 40
//20 40 30 50 60 20 80
//
//3
//20 80 70
//10 30 20
//�� ���� ���̽��� �ؼ� �ִ� �ּҸ� ���� ������ �� �ۿ� ����.
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		init();
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		dp[0][1] = arr[0][1] + dp[1][0];
		dp[1][1] = arr[1][1] + dp[0][0];

		for (int i = 2; i < n; i++)
		{
			dp[0][i] = arr[0][i] + std::max(dp[1][i - 1], dp[1][i - 2]);
			dp[1][i] = arr[1][i] + std::max(dp[0][i - 1], dp[0][i - 2]);
		}


		cout << std::max(dp[0][n - 1], dp[1][n - 1]) << endl;
	}


	return 0;
}