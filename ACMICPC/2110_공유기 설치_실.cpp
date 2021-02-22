
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
int N, C;
vector<int> pos_home;
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
	cin >> N >> C;
	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		pos_home.push_back(input);
	}
	sort(pos_home.begin(), pos_home.end());
	if (C == 2) {
		cout << pos_home[pos_home.size() - 1] - pos_home[0] << '\n';
		return 0;
	}
	else {
		//������ ���� �Ÿ��� �̺� Ž���� Ž�� ������� ����
		//��� �������� ���� �����ϱ� ����, ��ŭ ������ ���� �ξ�� �ϴ���
		int left = 1;
		int right = pos_home[N - 1] - pos_home[0];
		int d = 0;
		int ans = 0;
		while (left <= right) {
			int mid = (left + right) / 2;
			int start = pos_home[0];
			int cnt = 1;
			for (int i = 1; i < N; i++) {
				d = pos_home[i] - start;
				if (mid <= d) {
					++cnt;
					start = pos_home[i];
				}
			}

			if (cnt >= C) {
				ans = mid;
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}