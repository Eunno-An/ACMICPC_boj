
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

int s, N, K, R1, R2, C1, C2;
int arr[9][9] = {};
// �׽�Ʈ ���̽� �ʱ�ȭ ��
void init()
{

}
int getColor(int x, int y, int time) {
	if (time == 0) {
		return 0;
	}
	int t = (N - K) / 2, j = (int)pow(N, time - 1);

	if (t * j <= x && x < (t + K) * j && t * j <= y && y < (t + K) * j) return 1;
	while (true) {
		if (x - j >= 0) x -= j;
		else break;
	}while (true) {
		if (y - j >= 0) y -= j;
		else break;
		
	}
	return getColor(x, y, time - 1);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i >= (N - K) / 2 && j >= (N - K) / 2 && i < (N + K) / 2 && j < (N + K) / 2) {
				arr[i][j] = 1;
			}
		}
	}
	//K= 3�� ��
	//s = 1 -> i >= 1 && i < 4 && j >= 1 && j < 4
	//s = 2 -> i >=
	
	for (int i = R1; i <= R2; i++) {
		for (int j = C1; j <= C2; j++) {
			cout << getColor(i, j, s);
		}
		cout << '\n';
	}

	return 0;
}