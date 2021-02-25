
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
int port[40001];
int dp[40001];
// �׽�Ʈ ���̽� �ʱ�ȭ ��
void init()
{

}
int b_search(int r, int val) {
	int l = 0, mid, result = r;
	while (l <= r) {
		mid = l + (r - l) / 2;
		if (dp[mid] >= val) {
			result = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return result;
}
int main()
{
	//�̺� Ž���� LIS�� ���� �ִ� ����,
	//lower_bound�� ���� �� �� ������ ���� �����غ��°͵� ����
	//LIS���� ����������, �̺� Ž���� ��� ������� ������
	//�� �������� �̺�Ž����, LIS�� ������ �� ���� ���� ����
	//dp �迭�� ������ �� ���� ���� ��, �� ���� ��� �� ����
	//n������ Ž���ϴ� �� ����, log n  ���� Ž���ϴ°� Ű ����Ʈ
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	cin >> n;
	int idx = 0;
	for (int i = 0; i < n; i++) { // ��� ���� ��´�
		cin >> port[i];
	}
	dp[0] = port[0]; 
	//dp �迭�� ���� �� �����ϴ� �κм��� �߿��� idx��°�� ��ġ�� ���� �����Ѵ�.
	for (int i = 1; i < n; i++) {
		if (port[i] > dp[idx]) {
			dp[++idx] = port[i];
		}
		else {
			int val = b_search(idx, port[i]);
			dp[val] = port[i];
		}
	}
	cout << idx + 1 << '\n';
	/*
	port : 4 2 6 3 1 5
	dp : 
	4
	idx = 0, port[i] < dp[idx] : val = b_search(0, 2), dp[val] = 2;
	b_search(0, 2): l=0, result = 0, return 0; val = 0, dp[0] = 2;

	dp:
	2
	port[i] > dp[idx] : dp[1] = 6

	dp:
	2 6
	val = b_search(1, 3), l = 0, result = 1
	while(0 <= 1) mid = 0 + 0; dp[0] < val, l = 1
	return 1
	dp[1] = 3
	
	dp:
	2 3

	*/

	return 0;
}