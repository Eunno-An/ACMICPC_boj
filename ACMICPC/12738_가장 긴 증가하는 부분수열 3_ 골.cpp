
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
int A;
int arr[1000001];
int dp[1000001];
// �׽�Ʈ ���̽� �ʱ�ȭ ��
void init()
{
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	
	cin >> A;
	init();
	int input;
	int count = 1;
	for (int i = 0; i < A; i++) {
		cin >> input;
		arr[i] = input;
	}
	//LIS�� �̺�Ž��
	dp[0] = arr[0];
	int idx = 0;
	for (int i = 1; i < A; i++) {
		if (dp[idx] < arr[i]) {
			//cout << "if:";
			dp[++idx] = arr[i];
			//count++;
		}
		else {
			//cout << "else:";
			int idx1 = lower_bound(dp, dp + idx, arr[i]) - dp;
			dp[idx1] = arr[i];
		}
		//cout << idx << '\n';
	}
	
	cout << idx + 1 << '\n';
	//10 1 11 2 3 4 5
	/*
	* dp: 10
	* dp: 1
	*/
	return 0;
}