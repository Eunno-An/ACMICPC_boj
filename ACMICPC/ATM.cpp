
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
int arr[1001];
// �׽�Ʈ ���̽� �ʱ�ȭ ��
void init()
{

}

int main()
{
	//7�� 7��
	//DP�� �ذ��� �� ���� �� ����.
	//DP[i] += DP[i-1] + arr[i];

	//�ذ� ���
	//arr[i]�� ��Ʈ�� ������ 
	//�� �ܰ� i������ 0���� i-1������ ���� ������ ���� �ּҽð��� ��.
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	//�� ����� ���� �����ϴµ� �ʿ��� �ð��� ���� �ּڰ��� ���ϴ� ���α׷�
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	ll result = 0;
	for (int i = 0; i < N; i++) {
		ll temp = 0;
		for (int j = 0; j < i; j++) {
			temp += arr[j];
		}
		result += temp + arr[i];
	}
	cout << result << '\n';
	return 0;
}