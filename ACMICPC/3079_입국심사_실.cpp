
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

#define MOD 1000000000 //�ʾ�ĥ
#define INT_MAX 987654321
#define MAX 100005

typedef long long int ll;
typedef pair<int, int> pii;

int N, M;
int arr[MAX];
// �׽�Ʈ ���̽� �ʱ�ȭ ��
void init()
{

}
ll calc(ll mid) {
	ll res = 0;
	for (int i = 0; i < N; i++) {
		res += mid / arr[i]; // �ð� mid ����, �ð� arr[i]��ŭ �ɸ��� �ɻ���� �� mid / arr[i]��ŭ�� ó���� �� �ִ�.
	}return res;
}
int main()
{
	/*
	M���� N���� �ɻ�뿡�� �ɻ�, �ּ��� �ð�
	N���� �ɻ� �ð��� �־���
	1. N <= M�� ��, �׻� N�� �� ä��ٰ� �ּҷ� �Ǵ°� �ƴ�
	7 10
	0��: 7�� 10��
	7��: 14�� 10��
	10��: 14�� 20��
	14��: 21�� 20��
	20��: 21�� 30�� or 21ch: 28�� 20��

	*/
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	ll lo = arr[0], hi = (ll)arr[N - 1] * M;
	ll ans = 0;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		ll c = calc(mid);
		if (c >= M) {
			ans = mid;
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}
	cout << ans << '\n';
	return 0;
}