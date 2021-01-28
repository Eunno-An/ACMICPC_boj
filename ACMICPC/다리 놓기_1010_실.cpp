
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
ll arr[35][35];
// �׽�Ʈ ���̽� �ʱ�ȭ ��
void init()
{
	for (int i = 1; i <= 30; i++) {
		for (int j = 1; j <= 30; j++) {
			arr[i][j] = 0;
		}
	}
	arr[1][1] = 1;
}
ll combi(int r, int c) {
	if (c == 1) {
		return arr[r][1] = 1;
	}
	if (r == c) {
		return arr[r][c] = 1;
	}
	if (arr[r][c]) {
		return arr[r][c];
	}
	return arr[r][c] = combi(r - 1, c - 1) + combi(r - 1, c);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		if (N == 1) {
			cout << M << '\n';
			continue;
		}
		cout << combi(M+1, N+1) << '\n';
	}


	return 0;
}