
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
#define MAX_LINE 2147483647
typedef long long int ll;
typedef pair<int, int> pii;
int K, N;
ll length[1000001];


ll result;
ll max_num[1000001];
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
	cin >> K >> N;
	
	ll input;
	ll max_line = -1;
	for (int i = 0; i < K; i++) {
		cin >> input;
		if (max_line < input) {
			max_line = input;
		}
		length[i] = input;
	}
	if (N == 1) {
		cout << max_line;
		return 0;
	}
	//1���� 21������� �������̸� Ž���ؾ� ��.
	//����� ���� �ϳ��ϳ��� �߿��ϳ�..
	ll max_length = 0;
	ll lo = 1, hi = max_line;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		ll sum = 0;
		for (int i = 0; i < K; i++) {
			sum += length[i] / mid;
		}
		if (sum >= N) {
			lo = mid+1;
		}
		else {
			hi = mid-1;
		}
		
	}
	cout << hi << '\n';
	
	return 0;
}