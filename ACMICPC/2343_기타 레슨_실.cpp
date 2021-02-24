
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
int N, M;
ll lessons[100001];
// �׽�Ʈ ���̽� �ʱ�ȭ ��
void init()
{

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	init();
	ll S = 0;
	ll input;
	ll lo = -1;
	for (int i = 0; i < N; i++) {
		cin >> lessons[i];
		S += lessons[i];
		lo = max(lo, lessons[i]);
	}
	if (M == 1) {
		cout << S << '\n';
		return 0;
	}
	//sort(lessons.begin(), lessons.end());
	
	// �ϴ� ���� ū ���� ��緹�� �ϳ��� ��, �ϳ��� ���� �� �־�� �ϴϱ�!
	ll hi = S;
	while (lo <= hi) {
		ll cnt = 0, tempSum = 0;
		ll mid = (lo + hi) / 2;
		for (int i = 0; i < N; i++) {
			if (tempSum + lessons[i] > mid) {
				tempSum = 0;
				cnt += 1;
			}
			tempSum += lessons[i];
		}
		if (tempSum != 0) cnt += 1;
		if (cnt <= M) {
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}
	cout << lo << '\n';
	//https://chanhuiseok.github.io/posts/baek-22/
	return 0;
}