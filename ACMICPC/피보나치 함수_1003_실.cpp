
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
int arr_zero[51] = {};
int arr_first[51] = {};
int zero_count = 0;
int first_count = 0;
// �׽�Ʈ ���̽� �ʱ�ȭ ��
void init()
{
	for (int i = 0; i < 51; i++) {
		arr_zero[i] = 0;
		arr_first[i] = 0;
	}
}

int fibonacci_zero(int N) {
	if (N == 0) {
		return arr_zero[0] = 1;
	}
	if (N == 1) {
		return 0;
	}
	if (arr_zero[N]) {
		return arr_zero[N];
	}
	return arr_zero[N] = fibonacci_zero(N - 1) + fibonacci_zero(N - 2);
}
int fibonacci_first(int N) {
	if (N == 0) {
		return 0;
	}if (N == 1) {
		return arr_first[1] = 1;
	}if (arr_first[N]) {
		return arr_first[N];
	}return arr_first[N] = fibonacci_first(N - 1) + fibonacci_first(N - 2);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--) {
		init();
		int N;
		cin >> N;
		cout << fibonacci_zero(N) << ' '  << fibonacci_first(N) << '\n';
	}


	return 0;
}