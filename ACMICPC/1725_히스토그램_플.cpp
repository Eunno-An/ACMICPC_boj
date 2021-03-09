
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
ll arr[100001];
// �׽�Ʈ ���̽� �ʱ�ȭ ��
void init()
{

}
void solve() {
	ll max_result = 0;
	stack<int> s;
	int idx = 0;
	while (idx < N) {
		if (s.empty() || arr[s.top()] <= arr[idx]) {//���� ������ ������׷��� ���̰�, ����� ������׷����� �� ���� ���, Ǫ�� ����. 
			//�ֳ��ϸ� ������ �ִ� (���� ������׷�)���, ���� ������(ū ������׷�)��
			//�ڸ� �� �����ϱ�, �ĺ��� �ִ°Ŵ�.
			//���ÿ� �ִ� ����, �� ������׷��� �ε����̴�.
			s.push(idx++);
		}
		else {
			//���� ������ ������׷��� ���̰�, ����� ������׷� �ĺ����� ���������� �� ���� ����̴�.


			//������ ����� ������׷����� �ݵ�� (�������� ����)�� �Ǿ����� ���̴�.
			//�׷���, ���� ���� ������, �� ������ �����Ƿ� 
			//�� ������ ���������� �� ���� ���ÿ��� pop �ؾ� �Ѵ�.
			//else�������� �� �ѹ� pop�� ������, idx�� ������������ �����Ƿ�, ���� while���� ���ؼ�, arr[idx]���� �� �۰ų� ���� ���� ���� ������ pop���ְ� �ȴ�.
			
			//2 4 5 1�̶�� input����, 1�� ������ ���� ������ ����.
			//5, 4*2, 2 * 3�� ������ָ鼭 max���� ���ŵ� ���̴�. �������� 2*3�� ������ ������� ��, idx-s.top() -1�� �ϰ� �Ǹ� ������ �߻��ϹǷ�, ����ó���� �� �ذ��̤���.
			
			int tp = s.top();
			s.pop();
			ll area = arr[tp] * (ll)(s.empty() ? idx : idx - s.top() - 1);
			if (max_result < area) {
				max_result = area;
			}
		}
	}
	while (s.empty() == false) {
		int tp = s.top();
		s.pop();
		ll area = arr[tp] * (s.empty() ? idx : idx - s.top() - 1);
		if (max_result < area) {
			max_result = area;
		}
	}
	cout << max_result << '\n';

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	solve();

	return 0;
}