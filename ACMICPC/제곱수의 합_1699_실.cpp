
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
int dp[100001];
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

	//1 = 1
	//2 = 1 1
	//3 = 1 1 1
	//4 = 2
	//5 = 2 1
	//6 = 2 1 1
	//7 = 2 1 1 1
	//8 = 2
	//9 = 3
	//10 = 3 1
	//11 = 3 1 1
	//12 = 2 2 2
	//13 = 3 2
	//14 = 3 2 1
	//15 = 3 2 1 1
	//16 = 1
	//1 2 3 
	//1 2 3 4 1 
	//1 2 3 3 2 3 4 
	//1 2 3 3 2 3 3 4 3
	//1 2 1
	//19 = 3 3 1
	//20 = 3 3 1 1, 4 2
	//21 = 4 2 1
	//22 = 4 2 1 1, 3 3 2
	//23 = 3 3 2 1,
	//24 = 4 2 2
	cin >> N;
	for (int i = 1; i <= N; i++) {
		dp[i] = i;
		for (int j = 1; j <= sqrt(i); j++) {
			dp[i] = min(dp[i], dp[i - j * j]+1);
		}
	}
	cout << dp[N] << '\n';

	return 0;
}