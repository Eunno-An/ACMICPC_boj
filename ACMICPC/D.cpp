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

using namespace std;

/*
���� ��ȸ ID
	579_013
	ZgdxHXStpraTGmCT

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
int N, M;
int arr[2001][2001];
int before[2001][2001];
//������, �밢 ���� �Ʒ�, �Ʒ�, ���� �Ʒ�, ����, ���� ����, ����, ������ ����
int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 }; 
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
// �׽�Ʈ ���̽� �ʱ�ȭ ��
void init()
{
	
}

long long calculate_max(int x, int y, int m) {
	long long max = (long long)3000000000 * -1;
	for (int i = x; i < x + m; i++) {
		for (int j = y; j < y + m; j++) {
			if (arr[i][j] > max) {
				max = arr[i][j];
			}
		}
	}
	return max;
}

void fix_matrix(int x, int y, long long value) {
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = (M - 1) / 2; i <= N - (M - 1) / 2 - 1; i++) {
		for (int j = (M - 1) / 2; j <= N - (M - 1) / 2 - 1; j++) {
			if (j == (M - 1) / 2) {

			}
			before[i][j] = arr[i - M / 2][j - M / 2];

		}
	}
	if (N == M || M==1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << 0 << ' ';
			}
			cout << '\n';
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	

	return 0;
}